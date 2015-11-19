/**
  * CarBuilder.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;
 
 public abstract class CarBuilder 
 {
     public abstract void setSequence(ArrayList<String> sequence);
     public abstract CarModel getCarModel();
 }