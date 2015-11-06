#Design Pattern

##原则

<br>

##单一职责原则(Single Responsibility Principle)

>There should never be more than one reason for a class to change.

####好处

* 类的复杂性降低，实现什么职责都有清晰明确定义；
* 可读性提高，复杂性降低，那当然可读性提高了；
* 可维护性提高，可读性提高，那当然更容易维护了；
* 变更引起的风险降低，变更是必不可少的，如果接口的单一职责做得好，一个接口修改只对相应的实现类有影响，对其他的接口无影响，这对系统的扩展性、维护性都有非常大的帮助。 

####建议
>接口一定要做到单一职责，类的设计尽量做到只有一个原因引起变化。

<br>

##里氏替换原则(Liskov Substitution Principle)

>If for each object o1 for type S there is an object o2 of type T such that all programs P defined in terms of T,the behavior of P is unchanged when o1 is substituted for o2 then S is a subtyple of T.（如果对每一个类型为S的对象o1，都有类型为T的对象o2，使得以T定义的所有程序P在所有的对象o1都代换成o2时，程序P的行为没有发生变化，那么类型S是类型T的子类型。）

>Functions that use pointers or referencesss to base classes must be able to use objects of derived classes without knowing it.(所有引用基类的地方必须能透明地使用其子类的对象。)

1. 子类必须完全实现父类的方法
2. 子类可以有自己的个性
3. 覆盖或实现父类的方法时输入参数可以被放大（子类中方法的前置条件必须与超类中被覆写的方法的前置条件相同或者更宽松）
4. 覆写或实现父类的方法时输出结果可以被缩小

####目的

* 增加程序的健壮性，版本升级时也可以保持非常好的兼容性。即使增加子类，原有的子类还可以继续运行。

####建议
>采用里氏替换原则时，尽量避免子类的“个性”，一旦子类有“个性”，这个子类和父类之间的关系就很难调和了，把子类当做父类使用，子类的“个性”被抹杀(委屈点)；把子类单独作为一个业务使用，则会让代码间的耦合关系变得扑朔迷离(缺乏类替换的标准)。 

<br>

##依赖倒置原则(Dependence Inversion Principle)

>High level modules should not depend upon low level modules. Both should depend upon abstractios. Abstractions should not depend upon details. Details should depend upon abstractions.

1. 高层模块不应该依赖低层模块，两者都应该依赖其抽象；
2. 抽象不应该依赖细节；
3. 细节应该依赖抽象。

* 模块间的依赖通过抽象发生，实现类之间不发生直接的依赖关系，其依赖关系是通过接口或抽象类产生的；
* 接口或抽象类不依赖实现类；
* 实现类依赖接口或抽象类。

####写法
1. 构造函数传递依赖对象
2. Setter方法传递依赖对象
3. 接口声明依赖对象

####建议
>每个类尽量都有接口或抽象类，或者抽象类和接口两者都具备

>变量的表面类型尽量是接口或者是抽象类

>任何类都不应该从具体类派生

>尽量不要覆写基类的方法

>结合里氏替换原则使用

<br>

##接口隔离原则

>Client should not be forced to depend upon interfaces that they don't use.(客户端不应该依赖它不需要的接口。)

>The dependency of one class to another on should depend on the smallest possible interface.(类间的依赖关系应该建立在最小的接口上。)

* 接口要尽量小(根据接口隔离原则拆分接口时，首先必须满足单一职责原则)
* 接口要高内聚
* 定制服务
* 接口设计是有限度的

####建议
>一个接口只服务于一个子模块或者业务逻辑；

>通过业务逻辑压缩接口中的public方法，接口时常去回顾，尽量让接口达到“满身筋骨肉”，而不是“肥嘟嘟”的一大堆方法；

>已经被污染了的接口，尽量去修改，若变更的风险较大，则采用适配器模式进行转化处理；

>了解环境，拒绝盲从。每个项目或产品都有特定的环境因素，别看到大师是这样做的你就照抄。千万别，环境不同，接口拆分的标准就不同。深入了解业务逻辑，最好的接口设计就出自你的手中！

<br/>

##迪米特法则(Law of Demeter)

>Only talk to your immediate friends(只与直接的朋友通信。)

>最少知识原则(Least Knowledge Principle,LKP)。一个对象应该对其他对象有最少的了解，即，一个类应该对自己需要耦合或调用的类知道得最少，被耦合或调用的类的内部是如何复杂都和我没关系，那是你的事情，我就知道你提供的这么多public方法，我就调用这么多，其他的我一概不关心。

* 只和朋友交流
* 朋友间也是有距离的
* 是自己的就是自己的
* 谨慎使用Serializable

####建议
>迪米特法则的核心观念就是类间解耦，弱耦合，只有弱耦合了以后，类的复用率才可以提高。其要求的结果就是产生了大量的中转或跳转类，导致系统的复杂性提高，同时也维护带来了难度。

<br>
















