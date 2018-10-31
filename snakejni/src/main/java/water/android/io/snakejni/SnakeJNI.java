package water.android.io.snakejni;

public class SnakeJNI {

    static {
        System.loadLibrary("native-snake");
    }

    public native String getHelloWorld();
}
