package com.example.cleber.agenda_de_contatos;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Cleber on 18/01/2017.
 */

public class ContatoDAO extends SQLiteOpenHelper {
    private static final int VERSAO = 1;
    private static final String TABELA = "Contatos";
    private static final String DATABASE = "MinhaAgenda";

    public ContatoDAO(Context context) {
        super(context, DATABASE, null, VERSAO);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String dll = "CREATE TABLE " + TABELA
                +" (id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "nome TEXT NOT NULL," +
                "email TEXT," +
                "telefone TEXT," +
                "site TEXT," +
                "end TEXT," +
                "caminhoFoto TEXT);";
        db.execSQL(dll);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        if(oldVersion==1){
            String sql = "ALTER TABLE " + TABELA + " ADD COLUMN caminhoFoto TEXT;";
            db.execSQL(sql);
        }
    }

    public void adicionarContato(Contato contato){
        ContentValues values = new ContentValues();

        values.put("nome", contato.getNome());
        values.put("email", contato.getEmail());
        values.put("telefone", contato.getTelefone());
        values.put("site", contato.getSite());
        values.put("end", contato.getEnd());
        values.put("caminhoFoto", contato.getFoto());

        getWritableDatabase().insert(TABELA, null, values);
    }

    public void apagarContato(Contato contato){
        SQLiteDatabase db = getWritableDatabase();
        String[] args = {contato.getId().toString()};
        db.delete(TABELA, "id=?", args);
    }

    public void editarContato(Contato contato){
        ContentValues values = new ContentValues();

        values.put("nome", contato.getNome());
        values.put("email", contato.getEmail());
        values.put("telefone", contato.getTelefone());
        values.put("site", contato.getSite());
        values.put("end", contato.getEnd());
        values.put("caminhoFoto", contato.getFoto());

        String[] idAlterar = {contato.getId().toString()};

        getWritableDatabase().update(TABELA, values, "id=?", idAlterar);
    }

    public boolean verificaContato(String telefone){
        String[] args = {telefone};
        Cursor cursor = getReadableDatabase().rawQuery("SELECT telefone FROM "+TABELA+" WHERE telefone=?",args);
        int total=cursor.getCount();
        return total > 0; //se for maior que 0 retorna true
    }

    public List<Contato> listarContato(){
        List<Contato> contatos = new ArrayList<Contato>();
        Cursor cursor = getReadableDatabase().rawQuery("SELECT * FROM " + TABELA + ";",null);

        while (cursor.moveToNext()){
            Contato contato = new Contato();
            contato.setId(cursor.getLong(cursor.getColumnIndex("id")));
            contato.setNome(cursor.getString(cursor.getColumnIndex("nome")));
            contato.setEmail(cursor.getString(cursor.getColumnIndex("email")));
            contato.setSite(cursor.getString(cursor.getColumnIndex("site")));
            contato.setTelefone(cursor.getString(cursor.getColumnIndex("telefone")));
            contato.setEnd(cursor.getString(cursor.getColumnIndex("end")));
            contato.setFoto(cursor.getString(cursor.getColumnIndex("caminhoFoto")));
            contatos.add(contato);
        }
        cursor.close();
        return contatos;
    }
}
