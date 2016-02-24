/**
  * BenzModel.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;

public class BenzModel extends CarModel 
{
    protected void alarm()
    {
        System.out.println("BenzModel alarm...");
    }     

    protected void engineBoom()
    {
        System.out.println("BenzModel engineBoom...");
    }

    protected void start()
    {
        System.out.println("BenzModel start...");
    }

    protected void stop()
    {
        System.out.println("BenzModel stop...");
    }
}