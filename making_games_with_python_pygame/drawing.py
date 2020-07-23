import pygame, sys
from pygame.locals import *

pygame.init()

win = pygame.display.set_mode((500, 400))
pygame.display.set_caption('Drawing')

# Define some colors
BLACK = (  0,   0,   0)
WHITE = (255, 255, 255)
RED   = (255,   0,   0)
GREEN = (  0, 255,   0)
BLUE  = (  0,   0, 255)

# Draw some shapes on the surface win
win.fill(WHITE)
pygame.draw.polygon(win, GREEN, ((146, 0), (291, 106), (236, 277), (56, 277), (0, 106)))
pygame.draw.line(win, BLUE, (60, 60), (120, 60), 4)
pygame.draw.line(win, BLUE, (120, 60), (60, 120))
pygame.draw.line(win, BLUE, (60, 120), (120, 120), 4)
pygame.draw.circle(win, BLUE, (300, 50), 20, 0)
pygame.draw.ellipse(win, RED, (300, 250, 40, 80), 1)
pygame.draw.rect(win, RED, (200, 150, 100, 50))

pix_obj = pygame.PixelArray(win)
pix_obj[480][380] = BLACK
pix_obj[482][382] = BLACK
pix_obj[484][384] = BLACK
pix_obj[486][386] = BLACK
pix_obj[488][388] = BLACK
del pix_obj

while True:
	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
			sys.exit()
	
	pygame.display.update()