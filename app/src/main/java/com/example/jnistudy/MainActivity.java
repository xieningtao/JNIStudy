package com.example.jnistudy;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();

    }

    private void initView() {
        // Example of a call to a native method
        final TextView tv = findViewById(R.id.sample_text);
        findViewById(R.id.format_bt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tv.setText(formatName(tv.getText().toString()));

                String sign = SignUtils.getSign(MainActivity.this);
                Log.i(TAG, "sign: " + sign);

//                getValidToken(MainActivity.this);
            }
        });

        findViewById(R.id.to_another_bt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, AnotherJNIDemoActivity.class);
                startActivity(intent);
            }
        });
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String formatName(String name);

    public native String getValidToken(Object context);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
