# Pygame "hello world"
import pygame, sys
from pygame.locals import *

pygame.init()

# Create the window
win = pygame.display.set_mode((640, 480))

# Set the window's title
pygame.display.set_caption("Hello, World!")

while True: # main game loop
	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
			sys.exit()
	
	pygame.display.update()
