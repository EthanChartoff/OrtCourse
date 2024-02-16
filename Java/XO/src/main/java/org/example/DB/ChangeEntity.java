package org.example.DB;

public class ChangeEntity {
    private SQLCreator creator;
    private BaseEntity entity;
    private boolean isNew;


    public ChangeEntity(SQLCreator creator, BaseEntity entity, boolean isNew) {
        this.creator = creator;
        this.entity = entity;
        this.isNew = isNew;
    }

    public SQLCreator getCreator() {
        return creator;
    }

    public void setCreator(SQLCreator creator) {
        this.creator = creator;
    }

    public BaseEntity getEntity() {
        return entity;
    }

    public void setEntity(BaseEntity entity) {
        this.entity = entity;
    }

    public boolean isNew() {
        return isNew;
    }

    public void setNew(boolean aNew) {
        isNew = aNew;
    }
}
