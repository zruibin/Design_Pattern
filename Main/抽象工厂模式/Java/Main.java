/**
  * Main.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/07.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */

@SuppressWarnings("unused")
public class Main 
{
    public static void main(String[] args) 
    {
        HumanFactory maleHumanFactory = new MaleFactory();
        HumanFactory femaleHumanFactory = new FemaleFactory();

        System.out.println("------------------------------------------------------------");

        Human maleYellowHuman = maleHumanFactory.createYellowHuman();
        Human femaleYellowHuman = femaleHumanFactory.createYellowHuman();

        maleYellowHuman.getColor();
        maleYellowHuman.talk();
        maleYellowHuman.getSex();

        femaleYellowHuman.getColor();
        femaleYellowHuman.talk();
        femaleYellowHuman.getSex();

        System.out.println("------------------------------------------------------------");

        Human maleWhiteHuman = maleHumanFactory.createWhiteHuman();
        Human femaleWhiteHuman = femaleHumanFactory.createWhiteHuman();

        maleWhiteHuman.getColor();
        maleWhiteHuman.talk();
        maleWhiteHuman.getSex();

        femaleWhiteHuman.getColor();
        femaleWhiteHuman.talk();
        femaleWhiteHuman.getSex();

        System.out.println("------------------------------------------------------------");

        Human maleBlackHuman = maleHumanFactory.createBlackHuman();
        Human femaleBlackHuman = femaleHumanFactory.createBlackHuman();

        maleBlackHuman.getColor();
        maleBlackHuman.talk();
        maleBlackHuman.getSex();

        femaleBlackHuman.getColor();
        femaleBlackHuman.talk();
        femaleBlackHuman.getSex();

        System.out.println("------------------------------------------------------------");


    }

}









