package org.example.DB;

import org.example.xo.Game;

public class Main {
    public static void main(String[] args) {
        DB db = new GameDB();
        db.close();
    }
}
