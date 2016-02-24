/**
  * BMWModel.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;

public class BMWModel extends CarModel 
{
    protected void alarm()
    {
        System.out.println("BMWModel alarm...");
    }     

    protected void engineBoom()
    {
        System.out.println("BMWModel engineBoom...");
    }

    protected void start()
    {
        System.out.println("BMWModel start...");
    }

    protected void stop()
    {
        System.out.println("BMWModel stop...");
    }
}