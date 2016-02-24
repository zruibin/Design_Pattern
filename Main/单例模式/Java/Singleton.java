/**
  * Singleton.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */


public class Singleton 
{
    // private static final Singleton singleton = null;
    private static final Singleton singleton = new Singleton();

    private Singleton() {}

    public static Singleton getSingleton() {
        // if (singleton == null) {    
        //     synchronized (Singleton.class) {    
        //        if (singleton == null) {    
        //           singleton = new Singleton();   
        //        }    
        //     }    
        // } 
        return singleton;
    }

    public void print() {
        System.out.println("Singleton...");
    }

}

