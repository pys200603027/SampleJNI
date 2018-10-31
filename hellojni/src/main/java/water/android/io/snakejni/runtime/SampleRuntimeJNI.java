package water.android.io.snakejni.runtime;

public class SampleRuntimeJNI {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();
}
