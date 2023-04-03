#! /usr/local/bin/python3.11

# Import the necessary modules
import pygame

# Initialize the game engine
pygame.init()

# Define colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Set the screen size
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Create the screen
screen = pygame.display.set_mode([SCREEN_WIDTH, SCREEN_HEIGHT])

# Set the title of the window
pygame.display.set_caption('2D Game')

# Create the player
player_image = pygame.Surface([30, 30])
player_image.fill(BLACK)
player_rect = player_image.get_rect()

# Set the initial position of the player
player_rect.x = SCREEN_WIDTH / 2
player_rect.y = SCREEN_HEIGHT / 2

# Set the game loop to run at 60 FPS
clock = pygame.time.Clock()

# Game loop
done = False
while not done:
    # Check for events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

    # Update the player position
    player_rect.x += 5
    player_rect.y += 5

    # Fill the screen with white
    screen.fill(WHITE)

    # Draw the player on the screen
    screen.blit(player_image, player_rect)

    # Update the display
    pygame.display.flip()

    # Limit the frame rate
    clock.tick(60)

# Close the game
pygame.quit()