// it contains all xml file
/*********************content_main.xml*********************************/
<?xml version="1.0" encoding= "utf-8"?>
<RelativeLayout xmlns:android="http:schemas.android.com/apk/res/android"
   xmlns:app="http://schemas.android.com/apk/res-auto"
   xmlns:tool="http://schemas.android.com/tools"
   android:layout_width="match_parent"
   android:layout_height="match_parent"
   android:paddingBottom="@dimen/activity_vertical_margin"
   android:paddingLeft="@dimen/activity_horizontal_margin"
   android:paddingRight="@dimen/activity_horizontal_margin"
   android:paddingTop="@dimen/activity_vertical_margin"
   app:layout_behavior="@string/appbar_scrolling_view_behavior"
   tools:context="com.example.application.coffeebuzz.MainActivity"
   tools:showIn="@layout/activity_main">

   <ImageView
      android:layout_width="200dp"
      android:layout_height="100dp"
      android:src="@drawable/latte"
      android:contentDescription="@string/applogo"
      />
    <ListView
       android:layout_width="match_parent"
       android:layout_height="match_parent"
       android:id="@+id/list_options"
       android:entries="@array/options"
       />


</RelativeLayut>

/******************************strings.xml*****************************/
<resources>
   <string name="app_name">coffeeBuzz</string>
   <string name="action_setting">Settings</string>
   <sting name="applogo">CoffeBuzz</string>
   <stirng-array name="options">
      <item>Drinks</item>
      <item>Food</item>
      <item>Flater</item>
    </string-array>
</resources>
/*********************AndroidMainifest.xml*****************************/
<?xml version="1.0" endcoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
   package="com.example.application.coffeebuzz">

   <application
      android:allowBackup="true"
      android:icon="@mipmap/ic_launcher"
      android:lable="@string/app_name"
      android:supportsRtl="true"
      android:theme="#style/AppTheme">
      <activity
         android:name=".MainActivity"
         android:label="@string/app_name"
         android:theme="@style/AppTheme.NoActionBar">
         <intent-filter>
            <action android:name="android.intent.action.MAIN"/>
            <category android:name="android.intent.category.LAUNCHER"/>
         </intent-filter>
      </activity>

      <activity android:name".DrinkCategoryActivity"> //.java
      </activity>
   </application>
</manifest>
