#include "../config/config.h"
#define NUMERO_ATAQUES 4

static const char *labelBotoesCombate[] = {
    "FIGHT",
    "CAPTURE",
    "POKEMON",
    "RUN"
};

int tentar_fuga() {
    int saiu = 0;
    int valorAleatorio = rand() % 9;
    if (valorAleatorio <= 6) {
        saiu = 1;
    }
    return saiu;
}

Jogador_t configurar_oponente(Jogador_t jogador, Jogador_t jogadorPrincipal){
    Jogador_t oponent;
    int r;
    int i;

    for(i = 0; i<2; i++){
	    r = (rand() %6);
        oponent.pokemons[i] = jogador.pokemons[r];
        oponent.pokemons[i].xp = jogadorPrincipal.pokemons[0].xp + 100*((rand()%7)-3);
    }

    return oponent;
}

Texture2D selecionar_textura(Pokemon_t pokemon, Texturas_t texturas, bool costas) {
    if (strcmp(pokemon.nome, "CHURRASQUINHO") == 0) {
        return costas ? texturas.churrasquinhoCostas : texturas.churrasquinhoFrente;
    } else if (strcmp(pokemon.nome, "CHORAO") == 0) {
        return costas ? texturas.choraoCostas : texturas.choraoFrente;
    } else if (strcmp(pokemon.nome, "GRAMINHA") == 0) {
        return costas ? texturas.graminhaCostas : texturas.graminhaFrente;
    } else if (strcmp(pokemon.nome, "MORCEGAO") == 0) {
        return costas ? texturas.morcegaoCostas : texturas.morcegaoFrente;
    } else if (strcmp(pokemon.nome, "GONZAGUINHA") == 0) {
        return costas ? texturas.gonzaguinhaCostas : texturas.gonzaguinhaFrente;
    } else if (strcmp(pokemon.nome, "ZEUS") == 0) {
        return costas ? texturas.zeusCostas : texturas.zeusFrente;
    } else {
        return texturas.personagemPrincipal; // Retorna uma textura padrão caso não encontre o Pokémon
    }
}

void desenhar_interface_dialogo(const char *mensagem) {
    int larguraCaixa = larguraMonitor * 0.6;
    int alturaCaixa = alturaMonitor * 0.2;
    int xCaixa = (larguraMonitor - larguraCaixa) / 2;
    int yCaixa = alturaMonitor - alturaCaixa - 20;

    DrawRectangle(xCaixa, yCaixa, larguraCaixa, alturaCaixa, LIGHTGRAY);
    DrawRectangleLines(xCaixa, yCaixa, larguraCaixa, alturaCaixa, BLACK);

    int larguraTexto = MeasureText(mensagem, 20);
    int xTexto = xCaixa + (larguraCaixa - larguraTexto) / 2;
    int yTexto = yCaixa + (alturaCaixa - 20) / 2;
    DrawText(mensagem, xTexto, yTexto, 20, BLACK);

    DrawText(mensagem, xTexto + 1, yTexto + 1, 20, GRAY);
    EndDrawing();
    WaitTime(2);
}

void selecionar_ataques_aleatorios(Pokemon_t *pokemon, Ataque_t ataquesSelecionados[]) {
    int ataquesJaSelecionados[QUANTIDADE_ATAQUES_POR_POKEMON];
    for (int i = 0; i < QUANTIDADE_ATAQUES_POR_POKEMON; i++) {
        ataquesJaSelecionados[i] = 0;
    }

    int count = 0;
    while (count < NUMERO_ATAQUES) {
        int indiceAleatorio = rand() % QUANTIDADE_ATAQUES_POR_POKEMON;
        if (!ataquesJaSelecionados[indiceAleatorio]) {
            ataquesSelecionados[count] = pokemon->ataques[indiceAleatorio];
            ataquesJaSelecionados[indiceAleatorio] = 1;
            count++;
        }
    }
}

void desenha_pokemons_jogador(Pokemon_t *player, Texturas_t *texturas, Texture2D *texturaPlayer, Jogador_t *jogadorPrincipal, Pokemon_t *opponent, int *combateAtivo, int *pokemonSelecionado) {
    int selection = 0;
    bool menuOpen = true;
    int espacamentoVertical = 120; // Espaçamento maior entre as opções
    int larguraImagem = 50; // Largura padrão para todas as imagens
    int alturaImagem = 50;  // Altura padrão para todas as imagens
    int margem = 20; // Margem entre elementos

    texturas->ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png");

    while (menuOpen) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (IsKeyPressed(KEY_TAB)) {
            menu_inicial_rodando = false;
            menu_erro_rodando = false;
            menu_opcoes_rodando = false;
            menuOpen = false;
        }

        // Exibe a lista de Pokémons do jogador
        for (int i = 0; i <= jogadorPrincipal->qtdPokemons; i++) {
            Color cor = (i == selection) ? RED : BLACK;
            int posYTexto = alturaMonitor / 4 + i * espacamentoVertical;
            int posXTexto = 0;

            if (i < jogadorPrincipal->qtdPokemons && strlen(jogadorPrincipal->pokemons[i].nome) > 0) {
                // Se o Pokémon está derrotado, desabilita a seleção
                if (jogadorPrincipal->pokemons[i].vida <= 0) {
                    cor = GRAY; // Muda a cor do texto para indicar que está desabilitado
                }

                // Calcula a largura do texto para centralizar
                int larguraTexto = MeasureText(jogadorPrincipal->pokemons[i].nome, TAMANHO_FONTE_OPCOES_MENU);

                // Posição X centralizada para o texto
                int posXCentralizado = larguraMonitor / 2;

                // Desenha o nome do Pokémon centralizado
                posXTexto = posXCentralizado - (larguraTexto + larguraImagem + margem) / 2;
                DrawText(jogadorPrincipal->pokemons[i].nome, posXTexto, posYTexto, TAMANHO_FONTE_OPCOES_MENU, cor);

                // Desenha a barra de vida abaixo do nome, centralizada
                int larguraBarraVida = 200;
                int alturaBarraVida = 20;
                int posXBarra = posXTexto + larguraTexto + margem;
                int posYBarra = posYTexto + (TAMANHO_FONTE_OPCOES_MENU / 2) - (alturaBarraVida / 2);
                DrawRectangle(posXBarra, posYBarra, larguraBarraVida, alturaBarraVida, LIGHTGRAY);
                DrawRectangle(posXBarra, posYBarra, (int)(larguraBarraVida * (jogadorPrincipal->pokemons[i].vida / jogadorPrincipal->pokemons[i].vidaMaxima)), alturaBarraVida, GREEN);

                // Determina a textura correta para o Pokémon
                Texture2D imagemPokemon;
                imagemPokemon = selecionar_textura(jogadorPrincipal->pokemons[i], *texturas, false);

                // Desenha a imagem do Pokémon à direita da barra de vida
                int posXImagem = posXBarra + larguraBarraVida + margem;
                int posYImagem = posYTexto - 10; // Ajusta a posição Y para centralizar verticalmente com o texto
                DrawTexturePro(imagemPokemon, (Rectangle){0, 0, imagemPokemon.width, imagemPokemon.height},
                               (Rectangle){posXImagem, posYImagem, larguraImagem, alturaImagem},
                               (Vector2){0, 0}, 0.0f, WHITE);
            } else if (i == jogadorPrincipal->qtdPokemons) {
                // Desenha a opção "Voltar" no final da lista
                int larguraTexto = MeasureText("Voltar", TAMANHO_FONTE_OPCOES_MENU);
                posXTexto = (larguraMonitor / 2) - (larguraTexto / 2);
                DrawText("Voltar", posXTexto, posYTexto, TAMANHO_FONTE_OPCOES_MENU, cor);
            }

            if (i == selection) {
                // Ajusta a posição do ponteiro para o início do texto
                int posXPonteiro = posXTexto - texturas->ponteiroMenuInicialTexture.width - margem;
                int posYPonteiro = posYTexto - 10;
                DrawTexture(texturas->ponteiroMenuInicialTexture, posXPonteiro, posYPonteiro, WHITE);
            }
        }

        EndDrawing();

        if (IsKeyPressed(KEY_DOWN)) {
            selection++;
            if (selection > jogadorPrincipal->qtdPokemons) selection = 0;
        }
        if (IsKeyPressed(KEY_UP)) {
            selection--;
            if (selection < 0) selection = jogadorPrincipal->qtdPokemons;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            if (selection == jogadorPrincipal->qtdPokemons) {
                // Voltar ao menu de combate
                menuOpen = false;
            } else if (jogadorPrincipal->pokemons[selection].vida > 0) {
                // Seleciona o Pokémon somente se ele tiver vida
                *pokemonSelecionado = true;
                *player = jogadorPrincipal->pokemons[selection];
                *texturaPlayer = selecionar_textura(jogadorPrincipal->pokemons[selection], *texturas, true);
                menuOpen = false;
            }
        }
    }

    UnloadTexture(texturas->ponteiroMenuInicialTexture);
}

int tentar_capturar(Pokemon_t *opponent){
    float vidaAtual = (float)opponent->vida;
    float vidaMaxima = (float)opponent->vidaMaxima;

    float chanceCaptura = 50.0f * (1-(vidaAtual / vidaMaxima));
    float randomValue = (float)(rand() % 100);

    if(randomValue < chanceCaptura){
        return true;
    } else {
        return false;
    }
}

void desenhar_opcoes_combate(InterfaceCombate_t *ui, int *combateAtivo, int *fugaBemSucedida, int *selection, int *menuAtaque, int *menuPokemonsDisponiveis, Pokemon_t *opponent, Jogador_t *jogadorPrincipal, Pokemon_t *player, Texture2D *texturaPlayer, Texturas_t texturas) {
    Rectangle boxes[] = {ui->fightBox, ui->bagBox, ui->pokemonBox, ui->runBox};
    int temEspacoNaMochila = 0;

    for (int i = 0; i < NUMERO_ATAQUES; i++) {
        Color cor = (i == *selection) ? RED : DARKGRAY;
        DrawRectangleRec(boxes[i], cor);
        int larguraTextoOpcao = MeasureText(labelBotoesCombate[i], 20);
        int xTextoOpcao = boxes[i].x + (boxes[i].width - larguraTextoOpcao) / 2;
        DrawText(labelBotoesCombate[i], xTextoOpcao, boxes[i].y + (boxes[i].height - 20) / 2, 20, WHITE);
    }

    if (IsKeyPressed(KEY_RIGHT) && *selection % 2 == 0) (*selection)++;
    if (IsKeyPressed(KEY_LEFT) && *selection % 2 == 1) (*selection)--;
    if (IsKeyPressed(KEY_DOWN) && *selection < 2) (*selection) += 2;
    if (IsKeyPressed(KEY_UP) && *selection > 1) (*selection) -= 2;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (*selection) {
            case 0:
                *menuAtaque = true;
                break;
            case 1:
                // Implementar ação do botão "CAPTURE"
                if(temEspacoNaMochila == 0){
                    desenhar_interface_dialogo("Sua mochila esta cheia de pokemons!");
                } else {
                    *combateAtivo = false;
                    if(tentar_capturar(opponent)) {    
                        jogadorPrincipal->qtdPokemons+=1;
                        desenhar_interface_dialogo("Pokemon capturado com sucesso!");
                        for(int i =0; i < jogadorPrincipal->qtdPokemons;i++){
                            if(strlen(jogadorPrincipal->pokemons[i].nome) == 0){
                                jogadorPrincipal->pokemons[i] = *opponent;
                                temEspacoNaMochila = 1;
                                break;
                            }
                        }
                    } else {
                        desenhar_interface_dialogo("Captura falhou!");
                        Ataque_t tipoAtaque = opponent->ataques[rand() % QUANTIDADE_ATAQUES_POR_POKEMON]; // Seleciona um ataque aleatório do oponente
                        ataqueOponente(opponent, player, tipoAtaque, texturas, texturaPlayer, combateAtivo, jogadorPrincipal);
                    }
                }
                
                break;
            case 2:
                // Implementar ação do botão "POKEMON"
                *menuPokemonsDisponiveis = true;
                break;
            case 3:
                if (tentar_fuga()) {
                    *fugaBemSucedida = true;
                    *combateAtivo = false;
                    
                    menu_inicial_rodando = false;
                    menu_opcoes_rodando = false;
                    menu_batalha_rodando = false;
                } else {
                    desenhar_interface_dialogo("FUGA FALHOU!");
                    EndDrawing();
                    WaitTime(2); // Mensagem fica visível durante 2 segundos
                }
                break;
            default:
                break;
        }
    }
}

void escolher_novo_pokemon_inimigo(Pokemon_t *opponent, Pokemon_t timeInimigo[], int quantidadePokemons) {
    int indiceAleatorio;
    int pokemonEscolhido = 0;

    // Tenta escolher um Pokémon aleatoriamente até encontrar um com vida > 0
    while (!pokemonEscolhido) {
        indiceAleatorio = rand() % quantidadePokemons; // Escolhe um índice aleatório
        if (timeInimigo[indiceAleatorio].vida > 0) {
            *opponent = timeInimigo[indiceAleatorio];
            desenhar_interface_dialogo(TextFormat("O oponente escolheu %s!", opponent->nome));
            pokemonEscolhido = 1;
        }
    }

    // Caso todos os Pokémons do oponente estejam derrotados (isso deve ser tratado antes)
    if (!pokemonEscolhido) {
        desenhar_interface_dialogo("Você derrotou todos os Pokémons do oponente!");
        // Aqui você pode adicionar lógica para finalizar a batalha, como retornar para o menu principal
    }
}

void atualizar_lista_pokemons(Jogador_t *jogadorPrincipal) {
    for (int i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
        if (jogadorPrincipal->pokemons[i].vida <= 0) {
            jogadorPrincipal->pokemons[i].vida = 0;  // Certifica que a vida está em 0
        }
    }
}

int jogador_tem_pokemons_vivos(Jogador_t *jogadorPrincipal) {
    for (int i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
        if (jogadorPrincipal->pokemons[i].vida > 0) {
            return true;
        }
    }
    return false;
}

void ataqueOponente(Pokemon_t *opponent, Pokemon_t *player, Ataque_t ataqueOponente, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *jogadorPrincipal) {
    int i = 0;

    // Atualiza a vida do Pokémon atual no jogadorPrincipal
    for (i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
        if (strcmp(player->nome, jogadorPrincipal->pokemons[i].nome) == 0) {
            jogadorPrincipal->pokemons[i].vida -= ataqueOponente.dano * (1 - (player->defesa - opponent->ataque) / 100);
            player->vida = jogadorPrincipal->pokemons[i].vida; // Atualiza a vida do player também
            break;
        }
    }

    desenhar_interface_dialogo(TextFormat("O oponente usou o ataque %s!", ataqueOponente.nome));
    WaitTime(2);

    if (player->vida <= 0) {
        player->vida = 0;
        jogadorPrincipal->pokemons[i].vida = 0; // Garante que a vida do Pokémon no array também seja 0
        desenhar_interface_dialogo(TextFormat("%s foi derrotado!", player->nome));
        WaitTime(2);

        atualizar_lista_pokemons(jogadorPrincipal);  // Atualiza a vida dos Pokémons

        if (jogador_tem_pokemons_vivos(jogadorPrincipal)) {
            int pokemonSelecionado = 0;
            desenha_pokemons_jogador(player, &texturas, texturaPlayer, jogadorPrincipal, opponent, combateAtivo, &pokemonSelecionado);

            if(pokemonSelecionado){
                // O ataque do oponente não deve ser repetido aqui
            }
        } else {
            desenhar_interface_dialogo("Todos os seus Pokémons foram derrotados!");
            WaitTime(2);
            menu_batalha_rodando = false; // Finaliza o combate se não houver mais Pokémons disponíveis
            *combateAtivo = false;
        }
    }
}

void desenhar_opcoes_ataque(InterfaceCombate_t *ui, int *selection, int *menuAtaque, Pokemon_t *player, Ataque_t ataquesSelecionados[], Pokemon_t *opponent, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *jogadorPrincipal) {
    Rectangle boxes[] = {ui->ataque1, ui->ataque2, ui->ataque3, ui->ataque4};

    for (int i = 0; i < NUMERO_ATAQUES; i++) {
        Color cor = (i == *selection) ? RED : DARKGRAY;
        DrawRectangleRec(boxes[i], cor);
        int larguraTextoOpcao = MeasureText(ataquesSelecionados[i].nome, 20);
        int xTextoOpcao = boxes[i].x + (boxes[i].width - larguraTextoOpcao) / 2;
        DrawText(ataquesSelecionados[i].nome, xTextoOpcao, boxes[i].y + (boxes[i].height - 20) / 2, 20, WHITE);
    }

    if (IsKeyPressed(KEY_RIGHT) && *selection < 3) (*selection)++;
    if (IsKeyPressed(KEY_LEFT) && *selection > 0) (*selection)--;

    if (IsKeyPressed(KEY_ENTER)) {
        // Implementar ações específicas ao selecionar um ataque
        opponent->vida -= ataquesSelecionados[*selection].dano * (1 - (opponent->defesa - player->ataque) / 100);
        *menuAtaque = false;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        desenhar_interface_dialogo(TextFormat("Voce usou o ataque %s!", ataquesSelecionados[*selection].nome));

        if (opponent->vida <= 0) {
            desenhar_interface_dialogo(TextFormat("Voce derrotou %s!", opponent->nome));

            // Ganhar XP
            player->xp += 50*(1-((opponent->xp/100) - (player->xp/100)));

            // Regenerar a vida de todos os Pokémons do jogador ao iniciar a batalha
            for (int i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
                jogadorPrincipal->pokemons[i].vida = jogadorPrincipal->pokemons[i].vidaMaxima;
            }

            // Atualiza o Pokémon principal (player) para refletir a vida regenerada
            for (int i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
                if (strcmp(player->nome, jogadorPrincipal->pokemons[i].nome) == 0) {
                    player->vida = jogadorPrincipal->pokemons[i].vidaMaxima;
                    break;
                }
            }

            menu_batalha_rodando = false;
            menu_inicial_rodando = false;
            *combateAtivo = false;

        } else {
            // O oponente ainda tem vida, então ele ataca de volta
            Ataque_t tipoAtaque = opponent->ataques[rand() % QUANTIDADE_ATAQUES_POR_POKEMON]; // Seleciona um ataque aleatório do oponente
            ataqueOponente(opponent, player, tipoAtaque, texturas, texturaPlayer, combateAtivo, jogadorPrincipal);
        }
    }
}

void desenhar_opcoes_ataque_inimigo(InterfaceCombate_t *ui, int *selection, int *menuAtaque, Pokemon_t *player, Ataque_t ataquesSelecionados[], Pokemon_t *opponent, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *opponentJogador, Jogador_t *jogadorPrincipal) {
    Rectangle boxes[] = {ui->ataque1, ui->ataque2, ui->ataque3, ui->ataque4};

    for (int i = 0; i < NUMERO_ATAQUES; i++) {
        Color cor = (i == *selection) ? RED : DARKGRAY;
        DrawRectangleRec(boxes[i], cor);
        int larguraTextoOpcao = MeasureText(ataquesSelecionados[i].nome, 20);
        int xTextoOpcao = boxes[i].x + (boxes[i].width - larguraTextoOpcao) / 2;
        DrawText(ataquesSelecionados[i].nome, xTextoOpcao, boxes[i].y + (boxes[i].height - 20) / 2, 20, WHITE);
    }

    if (IsKeyPressed(KEY_RIGHT) && *selection < 3) (*selection)++;
    if (IsKeyPressed(KEY_LEFT) && *selection > 0) (*selection)--;

    if (IsKeyPressed(KEY_ENTER)) {
        // Implementar ações específicas ao selecionar um ataque
        opponent->vida -= ataquesSelecionados[*selection].dano * (1 - (opponent->defesa - player->ataque) / 100);
        *menuAtaque = false;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        desenhar_interface_dialogo(TextFormat("Voce usou o ataque %s!", ataquesSelecionados[*selection].nome));
        EndDrawing();
        WaitTime(2);

        if (opponent->vida <= 0) {
            desenhar_interface_dialogo(TextFormat("Voce derrotou %s!", opponent->nome));
            EndDrawing();
            WaitTime(2);

            // Escolhe um novo Pokémon para o oponente se disponível
            if (opponentJogador->pokemons[1].vida > 0) {
                *opponent = opponentJogador->pokemons[1];  // Muda para o próximo Pokémon
                *texturaPlayer = selecionar_textura(*opponent, texturas, false); // Atualiza a textura do novo Pokémon do oponente
                desenhar_interface_dialogo(TextFormat("O oponente escolheu %s!", opponent->nome));
                EndDrawing();
                WaitTime(2);
            } else {
                // Caso contrário, o jogador vence a batalha
                desenhar_interface_dialogo("Você venceu a batalha!");
                EndDrawing();
                WaitTime(2);
                menu_batalha_rodando = false;
                *combateAtivo = false;
            }
        } else {
            // O oponente ainda tem vida, então ele ataca de volta
            Ataque_t tipoAtaque = opponent->ataques[rand() % QUANTIDADE_ATAQUES_POR_POKEMON]; // Seleciona um ataque aleatório do oponente
            ataqueOponente_inimigo(opponent, player, tipoAtaque, texturas, texturaPlayer, combateAtivo, opponentJogador, jogadorPrincipal);
        }
    }
}

void ataqueOponente_inimigo(Pokemon_t *opponent, Pokemon_t *player, Ataque_t ataqueOponente, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *opponentJogador, Jogador_t *jogadorPrincipal) {
    player->vida -= ataqueOponente.dano * (1 - (player->defesa - opponent->ataque) / 100);
    desenhar_interface_dialogo(TextFormat("O oponente usou o ataque %s!", ataqueOponente.nome));
    EndDrawing();
    WaitTime(2);
    int pokemonSelecionado = false;

    if (player->vida <= 0) {
        player->vida = 0;
        desenhar_interface_dialogo(TextFormat("%s foi derrotado!", player->nome));
        EndDrawing();
        WaitTime(2);

        atualizar_lista_pokemons(jogadorPrincipal);  // Atualiza a vida dos Pokémons

        if (jogador_tem_pokemons_vivos(jogadorPrincipal)) {
            desenha_pokemons_jogador(player, &texturas, texturaPlayer, jogadorPrincipal, opponent, combateAtivo, &pokemonSelecionado);
        } else {
            desenhar_interface_dialogo("Todos os seus Pokémons foram derrotados!");
            EndDrawing();
            WaitTime(2);
            menu_batalha_rodando = false; // Finaliza o combate se não houver mais Pokémons disponíveis
            *combateAtivo = false;
        }
    }
}

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent, Texturas_t texturas, Jogador_t *jogadorPrincipal) {
    int combateAtivo = true;
    int fugaBemSucedida = false;
    int menuAtaque = false;
    int menuPokemonsDisponiveis = false;
    int selection = 0;
    int pokemonSelecionado = 0;

    InterfaceCombate_t ui = {
        .optionsBox = {0, 0, 0, 0},
        .fightBox = {0, 0, 0, 0},
        .bagBox = {0, 0, 0, 0},
        .pokemonBox = {0, 0, 0, 0},
        .runBox = {0, 0, 0, 0},
        .ataque1 = {0, 0, 0, 0},
        .ataque2 = {0, 0, 0, 0},
        .ataque3 = {0, 0, 0, 0},
        .ataque4 = {0, 0, 0, 0}
    };

    int larguraOpcoes = larguraMonitor * 0.15;
    int alturaOpcoes = alturaMonitor * 0.1;
    int espacamentoOpcoes = larguraMonitor * 0.02;
    int xOpcoes = larguraMonitor - larguraOpcoes - espacamentoOpcoes;
    int yOpcoes = alturaMonitor / 1.2 - alturaOpcoes - espacamentoOpcoes;

    ui.fightBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.bagBox = (Rectangle){xOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.pokemonBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};
    ui.runBox = (Rectangle){xOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};

    int barraVidaX = xOpcoes - larguraOpcoes - espacamentoOpcoes;
    int barraVidaY = yOpcoes - (alturaOpcoes * 1.5);
    int larguraBarraHP = (2 * larguraOpcoes) + espacamentoOpcoes;
    int alturaBarraHP = alturaOpcoes * 0.5;
    int yBase = alturaMonitor - alturaOpcoes - espacamentoOpcoes;

    ui.ataque1 = (Rectangle){espacamentoOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque2 = (Rectangle){2 * espacamentoOpcoes + larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque3 = (Rectangle){3 * espacamentoOpcoes + 2 * larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque4 = (Rectangle){4 * espacamentoOpcoes + 3 * larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};

    // Seleciona os ataques aleatórios
    Ataque_t ataquesSelecionados[NUMERO_ATAQUES];
    selecionar_ataques_aleatorios(&player, ataquesSelecionados);

    // Determina as texturas do jogador e do oponente
    Texture2D texturaPlayer;
    Texture2D texturaOpponent;

    // Aqui você deve associar a textura correta do jogador
    texturaPlayer = selecionar_textura(player, texturas, true);
    texturaOpponent = selecionar_textura(opponent, texturas, false);
    // Atualiza o Pokémon principal (player) para refletir a vida regenerada
    for (int i = 0; i < jogadorPrincipal->qtdPokemons; i++) {
        if (strcmp(player.nome, jogadorPrincipal->pokemons[i].nome) == 0) {
            player.vida = jogadorPrincipal->pokemons[i].vida;
            break;
        }
    }

    while (combateAtivo) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int margemSuperior = alturaMonitor * 0.1;
        int margemLateral = larguraMonitor * 0.1;

        // Exibe informações sobre o inimigo
        DrawText(opponent.nome, margemLateral, margemSuperior, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", (int)(opponent.xp/100)), margemLateral + 200, margemSuperior, 20, DARKGREEN);
        DrawRectangle(margemLateral, margemSuperior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(margemLateral, margemSuperior + 30, (int)(larguraBarraHP * (float)opponent.vida / opponent.vidaMaxima), alturaBarraHP, RED);

        // Desenhando a barra de vida do jogador acima das opções
        DrawText(player.nome, barraVidaX, barraVidaY - 20, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", (int)(player.xp/100)), barraVidaX + larguraBarraHP - 100, barraVidaY - 20, 20, DARKGREEN);
        DrawRectangle(barraVidaX, barraVidaY, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(barraVidaX, barraVidaY, (int)(larguraBarraHP * (float)player.vida / player.vidaMaxima), alturaBarraHP, RED);

        // Desenha a imagem do Pokémon do jogador (à esquerda)
        DrawTexturePro(texturaPlayer, (Rectangle){0, 0, texturaPlayer.width, texturaPlayer.height},
                       (Rectangle){larguraMonitor / 4 - 100, alturaMonitor / 2, 200, 200},
                       (Vector2){0, 0}, 0.0f, WHITE);

        // Desenha a imagem do Pokémon oponente (à direita)
        DrawTexturePro(texturaOpponent, (Rectangle){0, 0, texturaOpponent.width, texturaOpponent.height},
                       (Rectangle){(larguraMonitor * 3 / 4) - 100, alturaMonitor / 4, 200, 200},
                       (Vector2){0, 0}, 0.0f, WHITE);

        if (menuAtaque) {
            desenhar_opcoes_ataque(&ui, &selection, &menuAtaque, &player, ataquesSelecionados, &opponent, texturas, &texturaPlayer, &combateAtivo, jogadorPrincipal);
        } else if (menuPokemonsDisponiveis) {
            atualizar_lista_pokemons(jogadorPrincipal);  // Atualiza a vida dos Pokémons antes de abrir a tela de seleção
            desenha_pokemons_jogador(&player, &texturas, &texturaPlayer, jogadorPrincipal, &opponent, &combateAtivo, &pokemonSelecionado);

            // Após a escolha do Pokémon, o ataque do oponente ocorre, mas apenas se um Pokémon foi selecionado
            if (pokemonSelecionado) {
                menuPokemonsDisponiveis = false;
                Ataque_t tipoAtaque = opponent.ataques[rand() % QUANTIDADE_ATAQUES_POR_POKEMON]; // Seleciona um ataque aleatório do oponente
                ataqueOponente(&opponent, &player, tipoAtaque, texturas, &texturaPlayer, &combateAtivo, jogadorPrincipal);
                pokemonSelecionado = 0; // Resetar a variável para evitar ataques repetidos
            }
        } else {
            desenhar_opcoes_combate(&ui, &combateAtivo, &fugaBemSucedida, &selection, &menuAtaque, &menuPokemonsDisponiveis, &opponent, jogadorPrincipal, &player, &texturaPlayer, texturas);
        }

        EndDrawing();
    }
}

void mostrar_tela_combate_inimigo(Pokemon_t player, Jogador_t opponent, Texturas_t texturas, Jogador_t *jogadorPrincipal) {
    int combateAtivo = true;
    int fugaBemSucedida = false;
    int menuAtaque = false;
    int menuPokemonsDisponiveis = false;
    int selection = 0;
    int pokemonSelecionado = false;

    InterfaceCombate_t ui = {
        .optionsBox = {0, 0, 0, 0},
        .fightBox = {0, 0, 0, 0},
        .bagBox = {0, 0, 0, 0},
        .pokemonBox = {0, 0, 0, 0},
        .runBox = {0, 0, 0, 0},
        .ataque1 = {0, 0, 0, 0},
        .ataque2 = {0, 0, 0, 0},
        .ataque3 = {0, 0, 0, 0},
        .ataque4 = {0, 0, 0, 0}
    };

    int larguraOpcoes = larguraMonitor * 0.15;
    int alturaOpcoes = alturaMonitor * 0.1;
    int espacamentoOpcoes = larguraMonitor * 0.02;
    int xOpcoes = larguraMonitor - larguraOpcoes - espacamentoOpcoes;
    int yOpcoes = alturaMonitor / 1.2 - alturaOpcoes - espacamentoOpcoes;

    ui.fightBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.bagBox = (Rectangle){xOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.pokemonBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};
    ui.runBox = (Rectangle){xOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};

    int barraVidaX = xOpcoes - larguraOpcoes - espacamentoOpcoes;
    int barraVidaY = yOpcoes - (alturaOpcoes * 1.5);
    int larguraBarraHP = (2 * larguraOpcoes) + espacamentoOpcoes;
    int alturaBarraHP = alturaOpcoes * 0.5;
    int yBase = alturaMonitor - alturaOpcoes - espacamentoOpcoes;

    ui.ataque1 = (Rectangle){espacamentoOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque2 = (Rectangle){2 * espacamentoOpcoes + larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque3 = (Rectangle){3 * espacamentoOpcoes + 2 * larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};
    ui.ataque4 = (Rectangle){4 * espacamentoOpcoes + 3 * larguraOpcoes, yBase, larguraOpcoes, alturaOpcoes};

    // Seleciona os ataques aleatórios do jogador
    Ataque_t ataquesSelecionados[NUMERO_ATAQUES];
    selecionar_ataques_aleatorios(&player, ataquesSelecionados);

    // Determina as texturas do jogador e do Pokémon do oponente atual
    Texture2D texturaPlayer = selecionar_textura(player, texturas, true);
    Texture2D texturaOpponent = selecionar_textura(opponent.pokemons[0], texturas, false); // Assumindo que o primeiro Pokémon do oponente é o atual

    while (combateAtivo) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int margemSuperior = alturaMonitor * 0.1;
        int margemLateral = larguraMonitor * 0.1;

        // Exibe informações sobre o Pokémon do oponente
        DrawText(opponent.pokemons[0].nome, margemLateral, margemSuperior, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", opponent.pokemons[0].xp), margemLateral + 200, margemSuperior, 20, DARKGREEN);
        DrawRectangle(margemLateral, margemSuperior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(margemLateral, margemSuperior + 30, (int)(larguraBarraHP * (float)opponent.pokemons[0].vida / opponent.pokemons[0].vidaMaxima), alturaBarraHP, RED);

        // Exibe a barra de vida do jogador acima das opções
        DrawText(player.nome, barraVidaX, barraVidaY - 20, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", player.xp), barraVidaX + larguraBarraHP - 100, barraVidaY - 20, 20, DARKGREEN);
        DrawRectangle(barraVidaX, barraVidaY, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(barraVidaX, barraVidaY, (int)(larguraBarraHP * (float)player.vida / player.vidaMaxima), alturaBarraHP, RED);

        // Desenha a imagem do Pokémon do jogador à esquerda em um tamanho maior
        DrawTexturePro(texturaPlayer, (Rectangle){0, 0, texturaPlayer.width, texturaPlayer.height},
                       (Rectangle){larguraMonitor / 4 - 100, alturaMonitor / 2, 200, 200},
                       (Vector2){0, 0}, 0.0f, WHITE);

        // Desenha a imagem do Pokémon oponente à direita em um tamanho maior
        DrawTexturePro(texturaOpponent, (Rectangle){0, 0, texturaOpponent.width, texturaOpponent.height},
                       (Rectangle){(larguraMonitor * 3 / 4) - 100, alturaMonitor / 4, 200, 200},
                       (Vector2){0, 0}, 0.0f, WHITE);

        if (menuAtaque) {
            desenhar_opcoes_ataque_inimigo(&ui, &selection, &menuAtaque, &player, ataquesSelecionados, &opponent.pokemons[0], texturas, &texturaPlayer, &combateAtivo, &opponent, jogadorPrincipal);
        } else if (menuPokemonsDisponiveis) {
            atualizar_lista_pokemons(jogadorPrincipal);  // Atualiza a vida dos Pokémons antes de abrir a tela de seleção
            desenha_pokemons_jogador(&player, &texturas, &texturaPlayer, jogadorPrincipal, &opponent.pokemons[0], &combateAtivo, &pokemonSelecionado);

            // Após a escolha do Pokémon, o ataque do oponente ocorre, mas apenas se um Pokémon foi selecionado
            if (pokemonSelecionado) {
                menuPokemonsDisponiveis = false;
                Ataque_t tipoAtaque = opponent.pokemons[0].ataques[rand() % QUANTIDADE_ATAQUES_POR_POKEMON]; // Seleciona um ataque aleatório do oponente
                ataqueOponente(&opponent.pokemons[0], &player, tipoAtaque, texturas, &texturaPlayer, &combateAtivo, jogadorPrincipal);
                pokemonSelecionado = 0; // Resetar a variável para evitar ataques repetidos
            }
        } else {
            desenhar_opcoes_combate(&ui, &combateAtivo, &fugaBemSucedida, &selection, &menuAtaque, &menuPokemonsDisponiveis, &opponent.pokemons[0], jogadorPrincipal, &player, &texturaPlayer, texturas);
        }

        EndDrawing();
    }
}
