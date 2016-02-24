/**
  * Main.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */

@SuppressWarnings("unused")
public class Main 
{
    public static void main(String[] args) 
    {
        Singleton singleton = Singleton.getSingleton();
        singleton.print();
    }

}
