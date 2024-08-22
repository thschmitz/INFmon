#include "../config/config.h"

#define TAMANHO_LINHA_ARQUIVO 256

static const char *labelBotoesMenuInicial[] = {
  "NOVO JOGO",
  "CARREGAR JOGO",
  "SAIR"
};

static const char *labelBotoesMenuOpcoes[] = {
  "VOLTAR PRO JOGO",
  "SALVAR JOGO",
  "VOLTAR TELA INICIAL"
};

static const char *labelBotoesMenuErro[] = {
  "VOLTAR PRO JOGO",
  "VOLTAR TELA INICIAL ( Salvamento automático )"
};

typedef struct {
  char nome[20];
  char descricao[50];
  Texture2D texturaFrente;
  Texture2D texturaCostas;
} PokemonInicial_t;

// Corrigindo a função measure_text para aceitar const char *
int measure_text(const char *text, int tamanhoFonte) {
  return MeasureText(text, tamanhoFonte);
}

void menu_opcoes(Jogador_t *jogadorPrincipal) {
  Texturas_t texturas;
  int selection = 0;
  int erro;
  int menuOpen = true;
  texturas.ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png"); 

  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

		if (IsKeyPressed(KEY_TAB)) {
      menu_inicial_rodando = false;
      menu_erro_rodando = false;
      menu_opcoes_rodando = false;
      menuOpen = false;
    }

    DrawText(tituloProjeto, larguraMonitor / 2 - (measure_text(tituloProjeto, TAMANHO_FONTE_TITULO_PRINCIPAL) / 2), 20, TAMANHO_FONTE_TITULO_PRINCIPAL, BLACK);
    for (int i = 0; i < 3; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoesMenuOpcoes[i], larguraMonitor / 2 - (measure_text(labelBotoesMenuOpcoes[i], TAMANHO_FONTE_OPCOES_MENU) / 2), alturaMonitor / 2 + i * 100, TAMANHO_FONTE_OPCOES_MENU, cor);
      if (i == selection) {
        int posX = (larguraMonitor / 2 - (measure_text(labelBotoesMenuOpcoes[i], TAMANHO_FONTE_OPCOES_MENU) / 2)) - texturas.ponteiroMenuInicialTexture.width - 10;
        int posY = alturaMonitor / 2 + i * 100 - texturas.ponteiroMenuInicialTexture.height / 2;
        DrawTexture(texturas.ponteiroMenuInicialTexture, posX, posY + 10, WHITE);
      }
    }

    EndDrawing();

    if (IsKeyPressed(KEY_DOWN)) {
      selection++;
      if (selection > 2) selection = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selection--;
      if (selection < 0) selection = 2;
    }

    if (IsKeyPressed(KEY_ENTER)) {
      menuOpen = false;
    }
  }

  UnloadTexture(texturas.ponteiroMenuInicialTexture);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Voltar pro jogo
        menu_inicial_rodando = false;
        menu_opcoes_rodando = false;
        menuOpen = false;
        break;
      case 1:
        // Salvar jogo
        erro = salvar_jogo(jogadorPrincipal);
        if(erro){
          menu_inicial_rodando = false;
          menu_opcoes_rodando = false;
          menu_erro_rodando = true;
        } else {
          menu_inicial_rodando = false;
          menu_opcoes_rodando = false;
          //menuOpen = false;
        }
        
        break;
      case 2:
        // Voltar menu inicial
        menu_inicial_rodando = true;
        menu_opcoes_rodando = false;
        menuOpen = false;
        break;
      default:
        break;
    }
  }
}

void menu_inicial(Jogador_t *jogadorPrincipal) {
  Texturas_t texturas;
  int selection = 0;
  int erro;
  int menuOpen = true;
  texturas.ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png"); 

  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

    DrawText(tituloProjeto, larguraMonitor / 2 - (measure_text(tituloProjeto, TAMANHO_FONTE_TITULO_PRINCIPAL) / 2), 20, TAMANHO_FONTE_TITULO_PRINCIPAL, BLACK);
    for (int i = 0; i < 3; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoesMenuInicial[i], larguraMonitor / 2 - (measure_text(labelBotoesMenuInicial[i], TAMANHO_FONTE_OPCOES_MENU) / 2), alturaMonitor / 2 + i * 100, TAMANHO_FONTE_OPCOES_MENU, cor);
      if (i == selection) {
        int posX = (larguraMonitor / 2 - (measure_text(labelBotoesMenuInicial[i], TAMANHO_FONTE_OPCOES_MENU) / 2)) - texturas.ponteiroMenuInicialTexture.width - 10;
        int posY = alturaMonitor / 2 + i * 100 - texturas.ponteiroMenuInicialTexture.height / 2;
        DrawTexture(texturas.ponteiroMenuInicialTexture, posX, posY + 10, WHITE);
      }
    }

    EndDrawing();

    if (IsKeyPressed(KEY_DOWN)) {
      selection++;
      if (selection > 2) selection = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selection--;
      if (selection < 0) selection = 2;
    }

    if (IsKeyPressed(KEY_ENTER)) {
      menuOpen = false;
    }
  }

  UnloadTexture(texturas.ponteiroMenuInicialTexture);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Novo Jogo
        menu_inicial_rodando = false;
        menuOpen = false;
        break;
      case 1:
        // Carregar Jogo
        erro = carregar_jogo(jogadorPrincipal);
        if(erro){
          menu_inicial_rodando = false;
          menu_erro_rodando = true;
          menu_opcoes_rodando = false;
        } else {
          menu_inicial_rodando = false;
          //menuOpen=true;
        }
        
        break;
      case 2:
        // Sair do jogo
        programa_rodando = false;
        break;
      default:
        break;
    }
  }
}

int salvar_jogo(Jogador_t *jogadorPrincipal){
  FILE *arq;
  int retorno;
  arq = fopen("data/save.bin", "wb");

  if(arq == NULL) {
    printf("Erro na criacao do arquivo .bin para salvamento dos dados\n");
    retorno = 1;
  } else {
    retorno = 0;
    fwrite(jogadorPrincipal, sizeof(Jogador_t), 1, arq);
    fclose(arq);
  }

  return retorno;
}

int carregar_jogo(Jogador_t *jogadorPrincipal){
  FILE *arq;
  int retorno;
  char line[TAMANHO_LINHA_ARQUIVO];
  arq = fopen("data/save.bin", "rb");

  if(arq == NULL){
    printf("Erro na leitura do arquivo .bin para salvamento dos dados\n");
    retorno = 1;
  } else {
    fread(jogadorPrincipal, sizeof(Jogador_t), 1, arq);
    retorno = 0;
  }

  fclose(arq);

  return retorno;
}

void menu_erro() {
  Texturas_t texturas;
  int selection = 0;
  int erro;
  int menuOpen = true;
  texturas.ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png"); 

  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

    DrawText(tituloProjeto, larguraMonitor / 2 - (measure_text(tituloProjeto, TAMANHO_FONTE_TITULO_PRINCIPAL) / 2), 20, TAMANHO_FONTE_TITULO_PRINCIPAL, BLACK);
    for (int i = 0; i < 2; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoesMenuErro[i], larguraMonitor / 2 - (measure_text(labelBotoesMenuErro[i], TAMANHO_FONTE_OPCOES_MENU) / 2), alturaMonitor / 2 + i * 100, TAMANHO_FONTE_OPCOES_MENU, cor);
      if (i == selection) {
        int posX = (larguraMonitor / 2 - (measure_text(labelBotoesMenuInicial[i], TAMANHO_FONTE_OPCOES_MENU) / 2)) - texturas.ponteiroMenuInicialTexture.width - 10;
        int posY = alturaMonitor / 2 + i * 100 - texturas.ponteiroMenuInicialTexture.height / 2;
        DrawTexture(texturas.ponteiroMenuInicialTexture, posX, posY + 10, WHITE);
      }
    }

    EndDrawing();

    if (IsKeyPressed(KEY_DOWN)) {
      selection++;
      if (selection > 1) selection = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selection--;
      if (selection < 0) selection = 1;
    }

    if (IsKeyPressed(KEY_ENTER)) {
      menuOpen = false;
    }
  }

  UnloadTexture(texturas.ponteiroMenuInicialTexture);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Voltar pro jogo
        menu_inicial_rodando = false;
        menu_erro_rodando = false;
        menu_opcoes_rodando = false;
        break;
      case 1:
        // Voltar pro menu principal
        menu_erro_rodando = false;
        menu_inicial_rodando = true;
        menu_opcoes_rodando = false;

        break;
      default:
        break;
    }
  }
}

// Graminha, churrasquinho e chorao
void menu_escolha_pokemon(Jogador_t *jogadorPrincipal, Pokemon_t pokemonsIniciais[3]) {
    typedef struct {
        const char *nome;
        const char *descricao;
        Texture2D texturaFrente;
        Texture2D texturaCostas;
    } PokemonInicial_t;

    PokemonInicial_t pokemonsIniciaisLista[3] = {
        {pokemonsIniciais[0].nome, "Pokémon de Grama", LoadTexture("texturas/graminha_frente.png"), LoadTexture("texturas/graminha_costas.png")},
        {pokemonsIniciais[1].nome, "Pokémon de Fogo", LoadTexture("texturas/churrasquinho_invertido.png"), LoadTexture("texturas/churrasquinho_costas.png")},
        {pokemonsIniciais[2].nome, "Pokémon de Água", LoadTexture("texturas/chorao2def.png"), LoadTexture("texturas/chorao2_costas.png")}
    };

    int selection = 0;
    bool menuOpen = true;

    while (menuOpen) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 3; i++) {
            Color cor = (i == selection) ? RED : BLACK;
            int posX = larguraMonitor / 4 * (i + 1) - 100;
            int posY = alturaMonitor / 2 - 100;

            // Desenha a imagem do Pokémon
            DrawTexturePro(pokemonsIniciaisLista[i].texturaFrente, (Rectangle){0, 0, pokemonsIniciaisLista[i].texturaFrente.width, pokemonsIniciaisLista[i].texturaFrente.height},
                           (Rectangle){posX, posY, 200, 200},
                           (Vector2){0, 0}, 0.0f, WHITE);

            // Desenha o nome do Pokémon
            DrawText(pokemonsIniciais[i].nome, posX, posY + 250, 20, cor);
        }

        EndDrawing();

        // Navegação no menu
        if (IsKeyPressed(KEY_RIGHT)) selection = (selection + 1) % 3;
        if (IsKeyPressed(KEY_LEFT)) selection = (selection - 1 + 3) % 3;

        // Confirmação da escolha
        if (IsKeyPressed(KEY_ENTER)) {
            // Atualiza o Pokémon do jogador com base na escolha
            if (selection == 0) {
                jogadorPrincipal->pokemons[0] = (Pokemon_t)pokemonsIniciais[0];
            } else if (selection == 1) {
                jogadorPrincipal->pokemons[0] = (Pokemon_t)pokemonsIniciais[1];
            } else if (selection == 2) {
                jogadorPrincipal->pokemons[0] = (Pokemon_t)pokemonsIniciais[2];
            }

            jogadorPrincipal->qtdPokemons = 1;

            menuOpen = false;  // Sai do loop após a escolha
        }
    }

    // Descarrega as texturas após o uso
    for (int i = 0; i < 3; i++) {
        UnloadTexture(pokemonsIniciaisLista[i].texturaFrente);
        UnloadTexture(pokemonsIniciaisLista[i].texturaCostas);
    }
}