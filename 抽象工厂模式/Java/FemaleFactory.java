/**
  * FemaleFactory.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 

public class FemaleFactory implements HumanFactory 
{
    public Human createYellowHuman() {
            return new FemaleYellowHuman();
    }

    public Human createBlackHuman() {
            return new FemaleBlackHuman();
    }

    public Human createWhiteHuman() {
            return new FemaleWhiteHuman();
    }
}