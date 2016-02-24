/**
  * Director.java
  * zruibin.asia
  *
  * Created by Ruibin.Chow on 15/11/18.
  * Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
  */
 
 import java.util.ArrayList;

 public class Director 
 {
    private ArrayList<String> sequence = new ArrayList();
    private BenzBuilder benzBuilder = new BenzBuilder();
    private BMWBuilder bmwBuilder = new BMWBuilder();

    public BenzModel getBenzModel()
    {
        this.sequence.clear();
        this.sequence.add("start");
        this.sequence.add("stop");
        this.benzBuilder.setSequence(this.sequence);

        return (BenzModel)this.benzBuilder.getCarModel();
    }

    public BMWModel getBMWModel()
    {
        this.sequence.clear();
        this.sequence.add("start");
        this.sequence.add("alarm");
        this.sequence.add("stop");
        this.bmwBuilder.setSequence(this.sequence);

        return (BMWModel)this.bmwBuilder.getCarModel();
    }
 }