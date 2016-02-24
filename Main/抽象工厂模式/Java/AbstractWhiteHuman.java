/**
  * AbstractWhiteHuman.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 

 public abstract class AbstractWhiteHuman implements Human 
{
    public void getColor() {
        System.out.println("WhiteHuman --> getColor.....");
    }

    public void talk() {
        System.out.println("WhiteHuman --> talk.....");
    }
}