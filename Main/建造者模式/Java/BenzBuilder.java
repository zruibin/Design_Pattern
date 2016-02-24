/**
  * BenzBuilder.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;
 
 public class BenzBuilder extends CarBuilder 
 {
    private BenzModel benz = new BenzModel();

     public void setSequence(ArrayList<String> sequence)
     {
            this.benz.setSequence(sequence);
     }

     public CarModel getCarModel()
     {
            return this.benz;
     }
 }