package com.example.cleber.app02_listas_customizadas;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * Created by Cleber on 06/01/2017.
 */

public class AdaptadorCustom  extends ArrayAdapter {
    public AdaptadorCustom(Context context, int resource) {
        super(context, resource);
    }

    @Override
    public void add(Object object) {
        super.add(object);
    }

    @Override
    public int getCount() {
        return super.getCount();
    }

    @NonNull

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        View row;
        row = convertView;
        DataHandler handler;
        if(convertView==null){
            LayoutInflater inflater = (LayoutInflater) this.getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            row = inflater.inflate(R.layout.layout_celula, parent, false);
            handler = new DataHandler();
            handler.imagem = (ImageView) row.findViewById(R.id.ivImagem);
            handler.modelo = (TextView) row.findViewById(R.id.tvNomeCarro);
            handler.marca = (TextView) row.findViewById(R.id.tvMarcaCarro);
            row.setTag(handler);
        }else{
            handler = (DataHandler)row.getTag();
        }
        DataProvider dataProvider;
        dataProvider = (DataProvider) this.getItem(position);
        handler.imagem.setImageResource(dataProvider.getImagem());
        handler.marca.setText(dataProvider.getMarca());
        handler.modelo.setText(dataProvider.getModelo());
        return row;
    }

    private class DataHandler {
        ImageView imagem;
        TextView marca;
        TextView modelo;
    }
}



