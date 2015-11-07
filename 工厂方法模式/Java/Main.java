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
        AbstractHumanFactory factory = new HumanFactory();

        Human whiteHuman = factory.createHuman(WhiteHuman.class);
        whiteHuman.getColor();
        whiteHuman.talk();

        System.out.println("");

        Human yellowHuman = factory.createHuman(YellowHuman.class);
        yellowHuman.getColor();
        yellowHuman.talk();

        System.out.println("");

        Human blackHuman = factory.createHuman(BlackHuman.class);
        blackHuman.getColor();
        blackHuman.talk();
    }

}
