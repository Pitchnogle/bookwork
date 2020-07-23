import pygame, sys, os
from pygame.locals import *

pygame.init()

FPS = 60
fps_clock = pygame.time.Clock()

# Set up the window
win = pygame.display.set_mode((400, 300), 0, 32)
pygame.display.set_caption('Animation')

WHITE = (255, 255, 255)

cat_img = pygame.image.load(os.path.join(os.getcwd(), 'cat.png'))
catx = 10
caty = 10
direction = 'right'

while True: # the main game loop
    win.fill(WHITE)

    if direction == 'right':
        catx += 5
        if catx == 280:
            direction = 'down'
    elif direction == 'down':
        caty += 5
        if caty == 220:
            direction = 'left'
    elif direction == 'left':
        catx -= 5
        if catx == 10:
            direction = 'up'
    elif direction == 'up':
        caty -= 5
        if caty == 10:
            direction = 'right'

    win.blit(cat_img, (catx, caty))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update()
    fps_clock.tick(FPS)