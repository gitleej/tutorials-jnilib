package com.ailee.tutorialsjnilib;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.ailee.tutorialsjnilib.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'tutorialsjnilib' library on application startup.
    static {
        System.loadLibrary("tutorialsjni");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // test PersonInterface
        PersonInterface personInterface = new PersonInterface();
        personInterface.setName("Zhang San");
        personInterface.setAge(18);
        String name = personInterface.getName();
        int age = personInterface.getAge();
        // 输出姓名和年龄
        Log.e("MainActivity", "Name: " + name + "\tAge: " + age);

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'tutorialsjnilib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}