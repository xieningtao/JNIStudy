package com.example.jnistudy;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    // Example of a call to a native method
    final TextView tv = findViewById(R.id.sample_text);
    findViewById(R.id.format_bt).setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            tv.setText(formatName(tv.getText().toString()));

            String sign = SignUtils.getSign(MainActivity.this);
            Log.i(TAG,"sign: "+sign);
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
