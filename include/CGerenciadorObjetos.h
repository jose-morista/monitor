#include "CObjeto.h"
class CGerenciadorObjetos{

private:
    //static SDL_Renderer *renderer;
    static int totalObjetos;
    static PoolNumeros numObjetos;
    static Objeto objetos[MAX_OBJETOS];

public:

    static Objeto GetObjeto(int id_objeto){
        return objetos[id_objeto];
    }

    static void Inicia(SDL_Renderer *render=NULL){
        totalObjetos = 0;
        for (int i=0;i<MAX_OBJETOS;i++)
            objetos[i] = NULL;
        numObjetos = new CPoolNumeros(MAX_OBJETOS);
    }

    static void Encerra(){
        for (int i=0;i<MAX_OBJETOS;i++){
            if (objetos[i]) delete objetos[i];
        }
        delete numObjetos;
    }

    static int CriaObjeto(int posx,int posy,char* nomeArquivoBMP,int retiraFundo=1,int opacidade=255,int idJanela=0){
        int resp = numObjetos->RetiraLivre();
        objetos[resp] = new CObjeto(posx,posy,nomeArquivoBMP,retiraFundo,opacidade,idJanela);
        totalObjetos++;
        return resp;
    }

    static int CriaObjetoOffScreen(int posx,int posy,OffscreenRenderer offRenderer,int retiraFundo=1,int opacidade=255,int idJanela=0){
        int resp = numObjetos->RetiraLivre();
        objetos[resp] = new CObjeto(posx,posy,offRenderer,retiraFundo,opacidade,idJanela);
        totalObjetos++;
        return resp;
    }

    static void DestroiObjeto(int idObjeto){
        numObjetos->DevolveUsado(idObjeto);
        delete objetos[idObjeto];
        totalObjetos--;
        objetos[idObjeto] = NULL;
    }

    inline static void SetValorIntObjeto(int idObjeto,int indice,int valor){
        objetos[idObjeto]->valoresInt[indice] = valor;
    }

    inline static void SetValorFloatObjeto(int idObjeto,int indice,float valor){
        objetos[idObjeto]->valoresFloat[indice] = valor;
    }

    inline static int GetValorIntObjeto(int idObjeto,int indice){
        return objetos[idObjeto]->valoresInt[indice];
    }

    inline static float GetValorFloatObjeto(int idObjeto,int indice){
        return objetos[idObjeto]->valoresFloat[indice];
    }

    inline static void GetPosicaoXY(int idObjeto, int *x,int *y){
        objetos[idObjeto]->GetXY(*x,*y);
    }

    inline static void Move(int idObjeto, int x,int y){
        objetos[idObjeto]->Move(x,y);
    }

    inline static void SetAngulo(int idObjeto, float angulo){
        objetos[idObjeto]->SetAngulo(angulo);
    }

    inline static float GetAngulo(int idObjeto){
        return objetos[idObjeto]->GetAngulo();
    }

    inline static void SetPivo(int idObjeto, int x, int y){
        objetos[idObjeto]->SetPivo(x,y);
    }

    inline static void SetPivo(int idObjeto, float relX, float relY){
        objetos[idObjeto]->SetPivo(relX,relY);
    }

    inline static void GetPivo(int idObjeto, int *x,int *y){
        objetos[idObjeto]->GetPivo(*x,*y);
    }

    inline static void SetFlip(int idObjeto, PIG_Flip valor){
        objetos[idObjeto]->SetFlip(valor);
    }

    inline static PIG_Flip GetFlip(int idObjeto){
        return objetos[idObjeto]->GetFlip();
    }

    inline static void SetDimensoes(int idObjeto, int altura, int largura){
        objetos[idObjeto]->SetDimensoes(altura,largura);
    }

    inline static void GetDimensoes(int idObjeto, int *altura, int *largura){
        objetos[idObjeto]->GetDimensoes(*altura,*largura);
    }

    inline static void GetDimensoesOriginais(int idObjeto, int *altura, int *largura){
        objetos[idObjeto]->GetDimensoesOriginais(*altura,*largura);
    }

    inline static void CriaFrame(int idObjeto, int xBitmap, int yBitmap,int altura,int largura){
        SDL_Rect r;
        r.x = xBitmap;
        r.y = yBitmap;
        r.h = altura;
        r.w = largura;
        objetos[idObjeto]->DefineFrame(&r);
    }

    inline static void SetColoracao(int idObjeto, PIG_Cor cor){
        objetos[idObjeto]->SetColoracao(cor);
    }

    inline static void SetOpacidade(int idObjeto, int valor){
        objetos[idObjeto]->SetOpacidade(valor);
    }

    inline static void Desenha(int id_objeto,OffscreenRenderer offRender=NULL){
        objetos[id_objeto]->Desenha(offRender);
    }

    inline static int TestaColisao(int id_objeto1,int id_objeto2){
        return objetos[id_objeto1]->Colisao(objetos[id_objeto2]);
    }

    inline static PIG_Cor **GetPixels(int id_objeto){
        return objetos[id_objeto]->GetPixels();
    }

    inline static void AtualizaPixels(int id_objeto,int retiraFundo=1,int opacidade=255){
        objetos[id_objeto]->AtualizaPixels(retiraFundo,opacidade);
    }
};


PoolNumeros CGerenciadorObjetos::numObjetos;
int CGerenciadorObjetos::totalObjetos;
Objeto CGerenciadorObjetos::objetos[MAX_OBJETOS];
//SDL_Renderer* CGerenciadorObjetos::renderer;
