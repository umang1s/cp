// mainactivity.java
//create a new java class named driks.java

/*****************drinks.java********************************************/
package com.example.application.coffeebuzz;
public class Drinks
{
    private String name;
    private String desc;
    private int imageID;

    public static final Drinks[] drinks=
    {
        new Drinks("Latte","desc for latte",R.drawable.Latte),  // Latte.png present in drawable
        new Drinks("cappuccino","desc for cappuccino",R.drawable.cap), //cap.png
        new Drinks("filter","desc for beans",R.drawable.beans)//beans.png
    }

    private Drinks(String name, String desc,int imageID)    //construnctor
    {
        this.name = name;
        this.desc = desc;
        this.imageID = imageID;
    }
    //some method
    public String getDesc() {return desc;}
    public String getName() {return name;}
    public int getImageID() {return imageID;}
    public String toString() {return this.name;}
}
/********************MainActivity.java************************************/
package com.example.applicatin.coffeebuzz;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity
{
    @override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        AdapterView.OnItemClickListener itemClickListener = new AdapterView.OnItemClickListener()
        {
            public void OnItemClick(AdapterView<?> parent, View view, int position , long id)
            {
                if(position==0)
                {
                    Itent intent = new Intent(MainActivity.this,DricksCategeryActivity.class);
                    startActivity(intent);
                    //now create a DrinkCategeryActivity.java class
                }
            }
        };
        ListView listView=(ListView) findViewById(R.id.List_option);
        listView.setOnItemClickListener(itemClickListener);
    }

    @Override
    public boolean onCreateOptionMenu(Menu menu)
    {
        getMenuInFlater().inflate(R.menu.menu_main,menu);
        return true;
    }
}


/***********************DrinkCategeryActivity.java**********************/
public com.example.application.coffeebuzz;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class DrinkCategeryActivity extends ListActivity
{
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        ListView listDrinks = getListView();
        ArrayAdapter<Drinks> listAdapter = new ArrayAdapter<Drinks>
        {
            this,
            android.R.layout.simple_List_item_1,
            Drinks.drinks
        };
        listDrinks.setAdapter(listAdapter);

        public void onListItemClic(ListView listView,View itemView,int position,long id)
        {
            Intent intent = new Intent(DrinksCategeryActivity.this,DrinkActivity.class);
            intent.putExtra(DrinkActivity.EXTRA_DRINKNO,(int)id);
            startActivity(intent);
            // create a new activity named DrinkActivity
        }
    }
}
/************************DrinkActivity********************************/
