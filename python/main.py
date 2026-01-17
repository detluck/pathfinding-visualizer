import pygame
from ui.ui import Ui
from ui.controls import Button
import ui.settings as colors

ui_test = Ui(50,50, 20)
button_surface = pygame.Surface((1280, 200))
button_surface.fill(colors.CYAN)
grid_surface = pygame.Surface((1280, 500))
grid_surface.fill((5,5,5))
button = Button(20, 20, 50, 50, colors.BLACK, colors.BLUE, "Start", button_surface)
while( ui_test.running ):
            button.draw_button()
            ui_test.display.blit(button_surface, (0,0))
            ui_test.display.blit(grid_surface, (0,201))
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    ui_test.running = False

                grid = ui_test.draw_grid(grid_surface)
                ui_test.draw_all(grid, grid_surface)
             

pygame.quit()
