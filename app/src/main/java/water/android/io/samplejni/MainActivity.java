package water.android.io.samplejni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import water.android.io.snakejni.SnakeJNI;
import water.android.io.snakejni.runtime.SampleRuntimeJNI;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(new SnakeJNI().getHelloWorld());
    }
}
