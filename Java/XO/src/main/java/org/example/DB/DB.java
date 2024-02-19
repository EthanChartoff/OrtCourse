package org.example.DB;

import java.sql.*;
import java.util.ArrayList;


public abstract class DB {
    // work on db, need changes to be worked on one time, so transactions work.
    static protected ArrayList<ChangeEntity> inserted = new ArrayList<>();
    static protected ArrayList<ChangeEntity> updated = new ArrayList<>();
    static protected ArrayList<ChangeEntity> deleted = new ArrayList<>();

    protected final Connection connection;

    // work with db funcs
    protected abstract DB me();
    protected abstract BaseEntity createModel(BaseEntity entity) throws SQLException;
    protected abstract BaseEntity newEntity();

    public abstract PreparedStatement createInsertSql(BaseEntity entity);
    public abstract PreparedStatement createUpdateSql(BaseEntity entity);
    public abstract PreparedStatement createDeleteSql(BaseEntity entity);


    protected DB() {
        this.connection = DBConnection.newConnection();
        try {
            connection.setAutoCommit(false);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        try {
            this.connection.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public int saveChanges() {
        int rows = 0;
        PreparedStatement stmt;
        ResultSet res;

        try {
            for(ChangeEntity item : inserted) {
                stmt = item.getCreator().CreateSql(item.getEntity(), connection);
                rows += stmt.executeUpdate();

                if(item.isNew()) {
                    res = stmt.getGeneratedKeys();
                    if(res.next())
                        item.getEntity().setId(res.getInt(1));
                }
            }
            for(ChangeEntity item : updated) {
                stmt = item.getCreator().CreateSql(item.getEntity(), connection);
                rows += stmt.executeUpdate();
            }
            for(ChangeEntity item : deleted) {
                stmt = item.getCreator().CreateSql(item.getEntity(), connection);
                rows += stmt.executeUpdate();
            }

            connection.commit();
        } catch (SQLException e) {
            try {
                connection.rollback();
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
            throw new RuntimeException(e);
        } finally {
            inserted.clear();
            updated.clear();
            deleted.clear();
        }

        return rows;
    }

    public ArrayList<BaseEntity> select(String stmtStr) {
        ArrayList<BaseEntity> list = new ArrayList<>();
        Statement stmt;
        ResultSet res;

        try {
            stmt = connection.createStatement();
            res = stmt.executeQuery(stmtStr);

            while (res.next()) {
                BaseEntity ent = newEntity();
                createModel(ent);
                list.add(ent);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return list;
    }

    public void insert(BaseEntity entity) {
        BaseEntity ent = newEntity();
        DB me = me();
        if(entity != null && entity.getClass() == ent.getClass()) {
            SQLCreator creator = (entity1, connection) -> me.createInsertSql(entity1);
            ChangeEntity changeEntity = new ChangeEntity(creator, entity, true);
            inserted.add(changeEntity);
        }
    }

    public void update(BaseEntity entity) {
        BaseEntity ent = newEntity();
        if(entity != null && entity.getClass() == ent.getClass()) {
            SQLCreator creator = (entity1, connection) -> me().createUpdateSql(entity1);
            ChangeEntity changeEntity = new ChangeEntity(creator, entity, true);
            updated.add(changeEntity);
        }
    }

    public void delete(BaseEntity entity) {
        BaseEntity ent = newEntity();
        DB me = me();
        if(entity != null && entity.getClass() == ent.getClass()) {
            SQLCreator creator = (entity1, connection) -> me.createDeleteSql(entity1);
            ChangeEntity changeEntity = new ChangeEntity(creator, entity, true);
            deleted.add(changeEntity);
        }
    }
}
