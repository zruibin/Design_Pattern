/**
  * AbstractHumanFactory.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 public abstract class AbstractHumanFactory 
 {
        public abstract <T extends Human> T createHuman(Class<T> c);    
 }