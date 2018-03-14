#!/usr/bin/env python
from queue import Queue
import pygame
import sys
import time
import random


dx = [0,0,-10,10]
dy = [10,-10,0,0]

from pygame.locals import *

FPS = 10
pygame.init()
fpsClock=pygame.time.Clock()

SCREEN_WIDTH, SCREEN_HEIGHT = 640, 480
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
surface = pygame.Surface(screen.get_size())
surface = surface.convert()
surface.fill((255,255,255))
clock = pygame.time.Clock()

pygame.key.set_repeat(1, 40)

GRIDSIZE=10
GRID_WIDTH = SCREEN_WIDTH / GRIDSIZE
GRID_HEIGHT = SCREEN_HEIGHT / GRIDSIZE
UP    = (0, -1)
DOWN  = (0, 1)
LEFT  = (-1, 0)
RIGHT = (1, 0)
    
screen.blit(surface, (0,0))

def draw_box(surf, color, pos):
    r = pygame.Rect((pos[0], pos[1]), (GRIDSIZE, GRIDSIZE))
    pygame.draw.rect(surf, color, r)

    

class Snake(object):
    def __init__(self):
        self.lose()
        self.color = (0,0,0)

    def get_head_position(self):
        return self.positions[0]

    def lose(self):
        self.length = 1
        self.positions =  [((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2))]
        self.direction = random.choice([UP, DOWN, LEFT, RIGHT])

    def point(self, pt):
        if self.length > 1 and (pt[0] * -1, pt[1] * -1) == self.direction:
            return
        else:
            self.direction = pt
    #def buscaApple(self, Apple_position):
        

    def move(self):
        cur = self.positions[0]
        x, y = self.direction
        new = (((cur[0]+(x*GRIDSIZE)) % SCREEN_WIDTH), (cur[1]+(y*GRIDSIZE)) % SCREEN_HEIGHT)
        if len(self.positions) > 2 and new in self.positions[2:]:
            self.lose()
        else:
            self.positions.insert(0, new)
            if len(self.positions) > self.length:
                self.positions.pop()
    
    def draw(self, surf):
        for p in self.positions:
            draw_box(surf, self.color, p)

class Apple(object):
    def __init__(self):
        self.position = (0,0)
        self.color = (255,0,0)
        self.randomize()

    def randomize(self):
        self.position = (random.randint(0, GRID_WIDTH-1) * GRIDSIZE, random.randint(0, GRID_HEIGHT-1) * GRIDSIZE)

    def draw(self, surf):
        draw_box(surf, self.color, self.position)

def check_eat(snake, apple):
    if snake.get_head_position() == apple.position:
        snake.length += 1
        apple.randomize()
        
def bfs(snake, apple):
    fila = Queue.Queue()
    
    s1 = snake.positions[0][0]
    s2 = snake.positions[0][1]
    
    fila.put((s1,s2))
    
    visited = []
    pai = []
    
    for i in range(642):
        visited.append([0])
        pai.append([0])
        for j in range(482):
            visited[i].append(0)
            pai[i].append(())
    
    pai[s1][s2] = (-1,-1)
    
    while(not fila.empty()):
        topo = fila.get()
    
        
        v = topo[0]
        u = topo[1]
       
        if(visited[v][u]): continue
        
        visited[v][u] = 1
    
        for i in range(4):
            xx = v + dx[i]
            yy = u + dy[i]
            if(xx >= 0 and xx <=640 and yy >= 0 and yy <= 480 and (xx,yy)not in snake.positions and not visited[xx][yy]):
                fila.put((xx,yy))
                pai[xx][yy] = (v,u)
                
            
    a1 = apple.position[0]
    a2 = apple.position[1]
    cont = 0
    
    print("A cobra esta em %d %d" %(s1,s2))
    print("A maca esta em %d %d"%(a1,a2))

    while(True):
        
        if(a1 == -1 and a2 == -1): break
        
        print(str(a1) + " " + str(a2))
        aux = pai[a1][a2]
        cont += 1
        if cont > 100: break
        a1 = aux[0]
        a2 = aux[1]
        
    

if __name__ == '__main__':
    snake = Snake()
    apple = Apple()
    while True:

        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == K_UP:
                    snake.point(UP)
                elif event.key == K_DOWN:
                    snake.point(DOWN)
                elif event.key == K_LEFT:
                    snake.point(LEFT)
                elif event.key == K_RIGHT:
                    snake.point(RIGHT)

      
        surface.fill((255,255,255))
        snake.move()
        check_eat(snake, apple)
        snake.draw(surface)
        apple.draw(surface)
        font = pygame.font.Font(None, 36)
        text = font.render(str(snake.length), 1, (10, 10, 10))
        textpos = text.get_rect()
        textpos.centerx = 20
        surface.blit(text, textpos)
        screen.blit(surface, (0,0))
        pygame.display.flip()
        pygame.display.update()
        fpsClock.tick(FPS + snake.length)
        
        