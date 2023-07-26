
每个Account都有自己的Publisher（该Account Subscribe的account）与Subscriber（Subscribe该account的account）

创建Account时调用SetEventCallback，设置回调函数。

创建Account时调用SetTimerPeriod ，其是设置一个lv_timer定时调用TimerCallbackHandler,TimerCallbackHandler里面调用创建Account时设置的回调函数。 param.event = EVENT_TIMER;


每个Account都有自己的一个PingPongBuffer(根据new时候传递给构造函数的参数决定，可以为0,那就没有PingPongBuffer);，没有PingPongBuffer仍可以在使用Notify操作与Pull操作(需要操作account设置了回调函数)。


Commit操作：是将数据提交到Account自己的PingPongBuffer

Notify操作：将数据或命令发给某一个account (publishers)

Pull操作：从某一个account (publishers)中拉取数据回来，如果没有设置回调函数account->SetEventCallback(onEvent)，就直接将这个account的PingPongBuffer里的数据返回。 数据在param->data_p中。



Publish操作:将该account的PingPongBuffer数据传递给各个Subscriber，并用Subscriber的回调函数处理。










