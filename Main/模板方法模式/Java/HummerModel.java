/**
  * HummerModel.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/17.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */

public abstract class HummerModel
{
    protected abstract void start();
    protected abstract void stop();
    protected abstract void alarm();
    protected abstract void engineBoom();

    final public void run()
    {
        this.start();
        this.engineBoom();
        if (this.isAlarm()) {
            this.alarm();
        }
        this.stop();
    }

    protected boolean isAlarm()
    {
        return true;
    }
}



