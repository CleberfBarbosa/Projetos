package com.example.cleber.app02_listas_customizadas;

import android.content.res.Configuration;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    ListView lvLista;
    TextView tvDetalhes;

    @Override
    protected void onSaveInstanceState(Bundle outState) { //salvando os dados da tela
        super.onSaveInstanceState(outState);
        final TextView textView = (TextView) findViewById(R.id.tvDetalhes);
        CharSequence detalhes = textView.getText();
        outState.putCharSequence("detalhes", detalhes);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) { //restaurando os dados da tela
        super.onRestoreInstanceState(savedInstanceState);
        final TextView textView = (TextView) findViewById(R.id.tvDetalhes);
        CharSequence detalhes = savedInstanceState.getCharSequence("detalhes");
        textView.setText(detalhes);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //Verifica orientação
        int orientacao = this.getResources().getConfiguration().orientation;
        if(orientacao == Configuration.ORIENTATION_PORTRAIT){ //se ele estive em orientação retrato vai entrar aqui
            setContentView(R.layout.activity_main);
        }else{//se estiver em orientação paisagem entra aqui
            setContentView(R.layout.activity_main_land);
        }


        lvLista = (ListView) findViewById(R.id.lvListaDeCarros);
        String modeloCarro[] = {"A3 Sedan Flex" ,
                "X3 nacional" ,
                "QQ nacional" ,
                "Tiggo5" ,
                "S10 High Country",
                "S10 Freeride",
                "C4 Picasso",
                "458 Speciale A"};
        String marcaCarro[] = {"AUDI" ,
                "BMW" ,
                "CHERY" ,
                "CHERY" ,
                "CHEVROLET",
                "CHEVROLET",
                "CITROEN",
                "FERRARI"};
        final String detalhesCarro[] = {"Depois de a BMW lançar o primeiro motor turbo bicombustível, em 2013, para o Série 3, a Audi apresentará sua versão quase 2 anos depois, em setembro. O sedã mais vendido da marca será o primeiro equipado com motor 1.4  flex nacional, de 150 cavalos de potência. A fabricação nacional virá de São José dos Pinhais (PR), revivendo a antiga parceria na planta da Volkswagen - as duas marcas fazem parte do mesmo grupo." ,
                "A fábrica de Araquari, em Santa Catarina, já é responsável pela montagem do Série 3, Série 1, X1, e ganhará mais um modelo até o final do ano. O utilitário esportivo X3 nacional seguirá a atualização no visual feita em 2014, com faróis e grade dianteiros mais ao estilo do Série 3. A traseira passou praticamente despercebida no facelift. O motor é conhecido 2.0, de 184 cavalos de potência, aliado a câmbio automático de 8 velocidades e tração integral." ,
                "Depois da estreia com o Celer em abril, é a vez do subcompacto QQ sair da fábrica de Jacareí (SP) neste segundo semestre. A nova geração, que atualmente é importada da China, manteve o motor 1.0 de três cilindros e 69 cv. A oferta de equipamentos é bem acima da média no segmento, com ar-condicionado, direção assistida e vidros e travas elétricos, e o preço promete ser competitivo." ,
                "O terceiro veículo a ser produzido pela Chery no Brasil será o Tiggo 5. Mas isso só acontecerá em 2016. Antes, o modelo começa a ser importado da China. Ele deve representar um salto evolutivo em relação ao jipinho vendido atualmente, tanto em design como em qualidade de construção, e irá concorrer diretamente com o JAC T6." ,
                "A picape foi apresentada no Salão de São Paulo em 2014, ainda como conceito, e aparece para ser a versão mais equipada e cara do modelo, com preço sugerido de R$ 163.800. Até junho, a S10 mais cara saía por R$ 154.550. A versão de luxo é inspirada no mercado dos Estados Unidos - onde as picapes grandes são as preferidas - e marca a estreia da cor vermelha na linha, no final de julho.",
                "Até o final do ano, a picape da Chevrolet ganha mais 3 versões para públicos diferentes. A única que tem preço e data definida é a Freeride, que reúne os equipamentos mais buscados pelos compradores. Ela será encontrada nas lojas por R$ 95.340 no final de julho. Já a configuração Advantage mira \"custo-benefício\", ou seja, menos equipamentos, mas a fabricante não divulgou o preço. A grande novidade é a Chassis Cab, apenas com cabine simples e chassis, para empresas que quiserem adaptar a S10 para uso comercial. ",
                "Reestilizado na Europa em 2013 e mostrado no Salão de São Paulo em 2014, o monovolume da marca francesa deve finalmente desembarcar no Brasil. Com mudanças visuais interessantes, ele ganhou mais espaço para bagagens, por causa da nova plataforma EMP2 do grupo PSA Peugeot Citroën, e também novas tecnologias. O motor deve ser o 1.6 THP utilizado pelas duas marcas. No entanto, o importado deve cobrar um custo alto dos brasileiros interessados.",
                "O importador oficial da Ferrari no Brasil promete para o 2º semestre o conversível mais potente da história da marca. A 458 Speciale A (de \"Aperta\", aberta em italiano) foi apresentada ao mundo no Salão de Paris de 2014 e vai de zero a 100 km/h em apenas 3 segundos, graças ao motor 4.5 V8, de 605 cv. O conversível terá produção limitada em 499 carros, e 2 deles tem como destino o Brasil. O preço ainda não foi definido."};
        int imagemCarro[] = {R.drawable.audia3,
                R.drawable.bmwx3,
                R.drawable.cherryqq,
                R.drawable.cherytiggo5,
                R.drawable.s10,
                R.drawable.s10freeride,
                R.drawable.c4picasso,
                R.drawable.f458specialea};

        AdaptadorCustom adaptador;
        adaptador = new AdaptadorCustom(getApplicationContext(), R.layout.layout_celula);
        int i = 0;

        for(String modelo:modeloCarro){
            DataProvider dataProvider = new DataProvider(marcaCarro[i],modeloCarro[i],imagemCarro[i]);
            i++;
            adaptador.add(dataProvider);
        }

        lvLista.setAdapter(adaptador);

        lvLista.setOnItemClickListener(new  AdapterView.OnItemClickListener() {
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {
                tvDetalhes = (TextView) findViewById(R.id.tvDetalhes);
                tvDetalhes.setText(detalhesCarro[position]);
            }
        });
    }
}
