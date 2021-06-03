#include"libone.h"
#include"player.h"
void load(struct PLAYER* p) {
	p->imgIdx = loadImage("assets/witch.png");
	p->imgW = 223;
	p->imgH = 500;
}
void init(struct PLAYER* p) {
	p->p.x = 100;
	p->p.y = height - p->imgH;
	p->vx = 3;
	p->initVy = -50;
	p->gravity = 1.62;
	p->jumpFlag = 0;
	p->limitPy = p->p.y;
	p->r.dx = 83;
	p->r.dy = 0;
	p->r.w = p->imgW - p->r.dx * 2+6;
	p->r.h = p->imgH;
}
void move(struct PLAYER* p) {
	p->p.x += p->vx;
	if (p->jumpFlag == 0) {
		if (isTrigger(KEY_SPACE)) {
			p->vy = p->initVy;
			p->jumpFlag = 1;
		}
	}
	if (p->jumpFlag == 1) { 
		p->p.y += p->vy;
		p->vy += p->gravity;
		if (p->p.y > p->limitPy) {
			p->p.y = p->limitPy;
			p->jumpFlag = 0;
		}
	}
}
void draw(struct PLAYER* p) {
	image(p->imgIdx, p->p.x, p->p.y);
}