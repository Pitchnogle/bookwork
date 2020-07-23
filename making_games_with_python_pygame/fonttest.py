import pygame, sys
from pygame.locals import *

pygame.init()

# Create the window
win = pygame.display.set_mode((400, 300))

# Set the window's title
pygame.display.set_caption("Font Test")

WHITE = (255, 255, 255)
GREEN = (  0, 255,   0)
BLUE  = (  0,   0, 255)

font_obj = pygame.font.Font('freesansbold.ttf', 32)
text_surf = font_obj.render('Hello, World!', True, GREEN, BLUE)
text_rect = text_surf.get_rect()
text_rect.center = (200, 150)

while True: # main game loop
	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
			sys.exit()
	
	win.fill(WHITE)
	win.blit(text_surf, text_rect)
	
	pygame.display.update()