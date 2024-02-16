package org.example.DB;

public class BaseEntity {
    private int id;

    public BaseEntity(int id) {
        this.id = id;
    }

    public BaseEntity() {
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
