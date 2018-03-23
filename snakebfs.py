#!/usr/bin/env python
from queue import Queue
import pygame
import sys
import time
import random


dx = [0,0,-10,10]
dy = [10,-10,0,0]
black = (0,0,0)
white = (255,255,255)
red = (255,0,0)

from pygame.locals import *

FPS = 50
pygame.init()
fpsClock=pygame.time.Clock()

SCREEN_WIDTH, SCREEN_HEIGHT = 500, 500
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
surface = pygame.Surface(screen.get_size())
surface = surface.convert()
surface.fill((255,255,255))
clock = pygame.time.Clock()

pygame.key.set_repeat(1, 40)

GRIDSIZE=10
GRID_WIDTH = SCREEN_WIDTH / GRIDSIZE
GRID_HEIGHT = SCREEN_HEIGHT / GRIDSIZE
UP    = (-1, 0)
DOWN  = (1, 0)
LEFT  = (0, -1)
RIGHT = (0, 1)
    
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
    def __init__(self,snake):
        self.position = (0,0)
        self.color = (255,0,0)
        self.randomize(snake)

    def randomize(self, snake):
        while(self.position in snake.positions):
            self.position = (random.randint(0, GRID_WIDTH-1) * GRIDSIZE, random.randint(0, GRID_HEIGHT-1) * GRIDSIZE)


    def draw(self, surf):
        draw_box(surf, self.color, self.position)

def check_eat(snake, apple):
    if snake.get_head_position() == apple.position:
        snake.length += 1
        apple.randomize(snake)
        
def bfs(snake, apple):
    fila = Queue()
    
    s1 = int(snake.positions[0][0])
    s2 = int(snake.positions[0][1])
    
    fila.put((s1,s2))
    
    visited = []
    pai = []
    
    for i in range(600+2):
        visited.append([0])
        pai.append([0])
        for j in range(600+2):
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
            if(xx >= 0 and xx <= 500 and yy >= 0 and yy <= 500 and (xx,yy)not in snake.positions and not visited[xx][yy]):
                fila.put((xx,yy))
                pai[xx][yy] = (v,u)
                
    


    a1 = int(apple.position[0])
    a2 = int(apple.position[1])
    
    if(not visited[a1][a2]):
        print("asiudhasudhsaduhasduhasduhasd\naushaushaudasyduasduygasduyasdyugasdytagsdgy\naygasdygasdygsadygasdygsa")
        pygame.quit()
        sys.exit()
    print("A cobra esta em %d %d" %(s1,s2))
    print("A maca esta em %d %d" %(a1,a2))
    movimentos = []
    movimentos.append((a1,a2))

    while(True):
        
        if(a1 == s1 and a2 == s2): break
        
        print(str(a1) + " " + str(a2))
        aux = pai[a1][a2]
      
        a1 = aux[0]
        a2 = aux[1]
        movimentos.append((a1,a2))

    movimentos.reverse()
    return movimentos
def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()
def menu():
    while(True):
        for event in pygame.event.get():
            print(event)
            if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
        font = pygame.font.Font(None, 36)
        text = font.render("Jogador", 1, (20, 10, 10))
        text2 = font.render("Distância de Manhattan", 1, (10, 10, 10))
        text3 = font.render("Buscar em Largura", 1, (30, 10, 10))
    
        textpos = surface.get_rect()
        surface.blit(text, (SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-100))
       
        surface.blit(text2, (SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2))
       
        surface.blit(text3, (SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2+100))
      
        screen.blit(surface, (0,0))
        pygame.display.flip()
        pygame.display.update()
        fpsClock.tick(FPS + snake.length)
        

if __name__ == '__main__':
    snake = Snake()
    apple = Apple(snake)
   
    op = menu()
    while True:


        surface.fill((255,255,255))
        movimentos = bfs(snake,apple)

        #if (len(movimentos) == 2):continue;

        surface.fill((255,255,255))
        
        for i in movimentos:
            x = int(snake.positions[0][0])
            y = int(snake.positions[0][1])
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
            xx = i[0]
            yy = i[1]
            left = False
            right = False
            down = False
            up = False
            if(x == xx and y == yy): continue

            print("%d %d" %(x,y))
            print("%d %d" %(xx,yy))
            if (x - 10) == xx and y == yy:
                up = True
            elif (x + 10) == xx and y == yy:
                down = True
            elif x == xx and (y + 10) == yy:
                right = True
            elif x == xx and (y - 10) == yy:
                left = True
            else:
                break
        
            if (left):
                
                snake.point(LEFT)
            elif (right):
                
                snake.point(RIGHT)
            elif (up):
                
                snake.point(UP)
            else:
                
                snake.point(DOWN)

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
            fpsClock.tick(FPS + snake.length/3)
        
       
        