package com.example.jnistudy;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.util.Base64;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SignUtils {

    public static String getSign(Context context) {
        String signValidString = "aaaaa";
        PackageInfo packageInfo = null;
        try {
            String myPackageName = "com.example.jnistudy";
            String packageName = context.getPackageName();


            packageInfo = context.getPackageManager().getPackageInfo(packageName, PackageManager.GET_SIGNATURES);
            if(packageInfo != null && packageInfo.signatures != null && packageInfo.signatures.length > 0) {
                return packageInfo.signatures[0].toCharsString();
            }

        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return signValidString;
    }


    public  PackageManager getPackageManager(){
        return null;
    }

    public  PackageInfo getPackageInfo(String packageName, int flags){
        return null;
    }

    public String getPackageName(){
        return null;
    }

}
