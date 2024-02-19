package org.example.DB;

import java.sql.PreparedStatement;
import java.sql.SQLException;

public class GameDB extends DB {
    public GameDB() {
        super();
    }

    @Override
    protected DB me() {
        return this;
    }

    @Override
    protected BaseEntity createModel(BaseEntity entity) throws SQLException {
        if(entity instanceof GameModel)
//            entity.starttime = ...
//       Userdb db = new UserDb();
//        entity.ply1= db.selectById();

            return createModel((GameModel) entity);
        return null;
    }

    @Override
    protected BaseEntity newEntity() {
        return new GameModel();
    }

    @Override
    public PreparedStatement createInsertSql(BaseEntity entity) {
        PreparedStatement sql = null;
        if(entity instanceof GameModel game) {
            String sqlStr = "INSERT INTO public.games(" +
                    "\"boardSize\", \"boardLayers\", tile00, tile01, tile02, tile10, tile11, tile12, tile20, tile21, tile22, \"moveCounter\", status, res)" +
                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
            try {
                sql = connection.prepareStatement(sqlStr);

                sql.setInt(1, game.getBoardSize());
                sql.setInt(2, game.getBoardLayers());
                sql.setInt(3, game.getTile00().ordinal());
                sql.setInt(4, game.getTile01().ordinal());
                sql.setInt(5, game.getTile02().ordinal());
                sql.setInt(6, game.getTile10().ordinal());
                sql.setInt(7, game.getTile11().ordinal());
                sql.setInt(8, game.getTile12().ordinal());
                sql.setInt(9, game.getTile20().ordinal());
                sql.setInt(10, game.getTile21().ordinal());
                sql.setInt(11, game.getTile22().ordinal());
                sql.setInt(12, game.getMoveCounter());
                sql.setInt(13, game.getStatus().ordinal());
                sql.setInt(14, game.getResult().ordinal());
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        return sql;
    }

    @Override
    public PreparedStatement createUpdateSql(BaseEntity entity) {
        PreparedStatement sql = null;
        if(entity instanceof GameModel game) {
            String sqlStr = "UPDATE public.games" +
                    "SET \"boardSize\"=?, \"boardLayers\"=?, tile00=?, tile01=?, tile02=?, tile10=?, tile11=?, tile12=?, tile20=?, tile21=?, tile22=?, \"moveCounter\"=?, status=?, res=?" +
                    "WHERE id=?;";
            try {
                sql = connection.prepareStatement(sqlStr);

                sql.setInt(1, game.getBoardSize());
                sql.setInt(2, game.getBoardLayers());
                sql.setInt(3, game.getTile00().ordinal());
                sql.setInt(4, game.getTile01().ordinal());
                sql.setInt(5, game.getTile02().ordinal());
                sql.setInt(6, game.getTile10().ordinal());
                sql.setInt(7, game.getTile11().ordinal());
                sql.setInt(8, game.getTile12().ordinal());
                sql.setInt(9, game.getTile20().ordinal());
                sql.setInt(10, game.getTile21().ordinal());
                sql.setInt(11, game.getTile22().ordinal());
                sql.setInt(12, game.getMoveCounter());
                sql.setInt(13, game.getStatus().ordinal());
                sql.setInt(14, game.getResult().ordinal());
                sql.setInt(15, game.getId());
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        return sql;
    }

    @Override
    public PreparedStatement createDeleteSql(BaseEntity entity) {
        PreparedStatement sql = null;
        if (entity instanceof GameModel game) {
            String sqlStr = "DELETE FROM public.games" +
                    "WHERE id=?;";
            try {
                sql = connection.prepareStatement(sqlStr);

                sql.setInt(1,   game.getId());
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        return sql;
    }
}
