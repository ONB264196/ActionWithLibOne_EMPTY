#include"libOne.h"
#include"game.h"
void load(struct GAME* g){
	load(&g->player);
	load(&g->obstacle);
}
void init(struct GAME* g){
	init(&g->player);
	init(&g->obstacle);
	g->state = g->PLAY; 
}
void play(struct GAME* g) {
	move(&g->player);
	move(&g->obstacle);
	draw(g);
	if (collision(&g->player, &g->obstacle)) {
		g->state = g->OVER;
	}
	if (g->player.p.x + g->player.imgW>width) {
		g->state = g->CLEAR;
	}
	
	textSize(50);
	fill(224, 225, 204);
	text("Goal", 1750, 700);
}
int collision(struct PLAYER* p, struct OBSTACLE* o) {
	float pLeft = p->p.x + p->r.dx;
	float pRight = pLeft + p->r.w;
	float pTop = p->p.y + p->r.dy;
	float pBottom = pTop + p->r.h;
	float oLeft = o->p.x + o->r.dx;
	float oRight = oLeft + o->r.w;
	float oTop = o->p.y + o->r.dy;
	float oBottom = oTop + o->r.h;
	if (pRight < oLeft || oRight < pLeft ||
		pBottom < oTop || oBottom < pTop) {
		return 0;
	}
	return 1;
}


void over(struct GAME* g) {
	draw(g);
	fill(200, 50, 50);
	textSize(200);
	text("GAME OVER", 490, 200);
	if (isTrigger(KEY_SPACE)) {
		g->state = g->INIT;
	}
}
void clear(struct GAME* g) {
	draw(g);
	fill(10, 30, 200);
	textSize(200);
	text("GAME CLEAR", 520, 200);
	if (isTrigger(KEY_SPACE)) {
		g->state = g->INIT;
	}
}
void draw(struct GAME* g) {
	clear(31, 30, 51);
	draw(&g->player);
	draw(&g->obstacle);
	drawRectArea(&g->player.p, &g->player.r);
	drawRectArea(&g->obstacle.p, &g->obstacle.r);
}
