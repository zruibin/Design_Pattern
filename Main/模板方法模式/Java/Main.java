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
        HummerH1Model h1 = new HummerH1Model();
        h1.setAlarm(false);
        h1.run();

        HummerH2Model h2 = new HummerH2Model();
        h2.run();
    }

}
