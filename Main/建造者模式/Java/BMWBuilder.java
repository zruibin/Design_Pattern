/**
  * BMWBuilder.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;

 public class BMWBuilder extends CarBuilder 
 {
    private BMWModel bmw = new BMWModel();

     public void setSequence(ArrayList<String> sequence)
     {
            this.bmw.setSequence(sequence);
     }

     public CarModel getCarModel()
     {
            return this.bmw;
     }
 }