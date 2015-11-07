/**
  * HumanFactory.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 public class HumanFactory extends AbstractHumanFactory 
 {
     public <T extends Human> T createHuman(Class<T> c) {
            Human human = null;

            try {
                    human = (T)Class.forName(c.getName()).newInstance();
            } catch(Exception e) {
                    System.out.println("error.....");
            }

            return (T)human;
     }
 }