package com.example.cleber.agenda_de_contatos;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.telephony.SmsMessage;

/**
 * Created by Cleber on 19/01/2017.
 */

public class SMSReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Bundle bundle = intent.getExtras();
        Object[] mensagens = (Object[]) bundle.get("pdus");

        byte[] mensagem = (byte[])mensagens[0];

        SmsMessage msg = SmsMessage.createFromPdu(mensagem);
        String telefone = msg.getDisplayOriginatingAddress();
        ContatoDAO contatoDAO = new ContatoDAO(context);

        if(contatoDAO.verificaContato(telefone)){
            MediaPlayer mediaPlayer = MediaPlayer.create(context, R.raw.msg);
            mediaPlayer.start();
        }
    }
}
