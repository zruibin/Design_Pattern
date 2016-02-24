/**
  * HummerH1Model.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/17.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 public class HummerH1Model extends HummerModel 
{
    private boolean alarmFlay = true;

    protected void alarm()
    {
        System.out.println("H1 alarm...");
    }     

    protected void engineBoom()
    {
        System.out.println("H1 engineBoom...");
    }

    protected void start()
    {
        System.out.println("H1 start...");
    }

    protected void stop()
    {
        System.out.println("H1 stop...");
    }

    protected boolean isAlarm()
    {
        return this.alarmFlay;
    }

    public void setAlarm(boolean isAlarm)
    {
        this.alarmFlay = isAlarm;
    }
}