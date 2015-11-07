/**
  * MaleFactory.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 

public class MaleFactory implements HumanFactory 
{
    public Human createYellowHuman() {
            return new MaleYellowHuman();
    }

    public Human createBlackHuman() {
            return new MaleBlackHuman();
    }

    public Human createWhiteHuman() {
            return new MaleWhiteHuman();
    }
}