/**
  * HummerH2Model.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/17.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 public class HummerH2Model extends HummerModel 
{
    protected void alarm()
    {
        System.out.println("H2 alarm...");
    }     

    protected void engineBoom()
    {
        System.out.println("H2 engineBoom...");
    }

    protected void start()
    {
        System.out.println("H2 start...");
    }

    protected void stop()
    {
        System.out.println("H2 stop...");
    }

    protected boolean isAlarm()
    {
        return false;
    }

}