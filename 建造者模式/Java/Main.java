/**
  * Main.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/17.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */

@SuppressWarnings("unused")
public class Main 
{
    public static void main(String[] args) 
    {
        Director director = new Director();

        for (int i=0; i<10; ++i) {
            director.getBenzModel().run();
        }

        System.out.println("------------------------------------------------------------------------");

        for (int i=0; i<5; ++i) {
            director.getBMWModel().run();
        }
    }

}
