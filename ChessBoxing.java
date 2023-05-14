package Sperms;

import java.io.*;
import java.util.*;

class ChessBoxing
{
    static int player_health = 100; // stores the health of the player
    static int dialogueSpeed = 40; // the speed at which the dialogue run
    static long sleepTime = 250; // the time for Thread.sleep()
    static int enemy_health = 100; // friend's health
    static int[] damage ={0, 10, 15, 24, 52, 69, 22, 31, 41, 39, 37, 1, 9, 3, 25}; // damage choosing from this array
    static Scanner sc = new Scanner(System.in); // for user input
    static Random rn = new Random(); // generates random numbers
    
    // method to slowly print a piece of text
    public static void slowPrint(String text, int speed) throws InterruptedException, IOException{
        // creating new writer object to flush stream
        Writer w = new PrintWriter(System.out);
        // looping through the text
        for(int t = 0; t < text.length(); t++){
          // printing the current character, flushing the stream and sleeping for some ms
          System.out.print(text.charAt(t));
          w.flush();
          Thread.sleep(speed);
        }
        System.out.println();
    }
    
    // method to display the intro
    static void displayIntro() throws InterruptedException, IOException{
        slowPrint("########################", 10);
        slowPrint("      Chess Boxing      ", 10);
        slowPrint("########################", 10);
        System.out.println("\n\n\n\n");
        
        // printing a few dialogues for the user to see
        slowPrint("[Friend] Hey, lets play a game of chess.", dialogueSpeed);
        Thread.sleep(sleepTime);
        slowPrint("[Player] Ok, but why do have gloves?", dialogueSpeed);
        Thread.sleep(sleepTime);
        slowPrint("[Friend] New chess variant called chess boxing", dialogueSpeed);
        Thread.sleep(sleepTime); 
        slowPrint("[Player] Sounds fun to play.", dialogueSpeed);
        Thread.sleep(sleepTime);      
        slowPrint("\nThe Match has started!\n", 60);
    }
    static void attackDisplay(String playerName)throws InterruptedException, IOException{
        // all possible moves for the user to give are printed
        slowPrint(playerName+"'s attack options:- ", 26);
        System.out.println("1. Sniper Bishoop");
        System.out.println("2. GIgachad Rook");
        System.out.println("3. Magic");
        System.out.println("4. Swift Pawn");
        System.out.print(">> ");
    }
    
    // method to damage the player or enemy at certain times
    static void damageEntity(int dmg, boolean isPlayer, boolean regen){
        // if the attack wasnot magic
        if(!regen){
          // if not player damage player else damage enemy
          if(!isPlayer) player_health -= dmg;
          else enemy_health -= dmg;
        }
        // if the attack was magic
        else{
          // if player heal player else heal enemy
          if(isPlayer) player_health += dmg;
          else enemy_health += dmg;
        }
        
    }
    
    // execution starts from here
    public static void main(String[] args) throws InterruptedException, IOException{
        displayIntro(); // displaying the intro
        // variable declaration
        int turn = 1, dmg, choice;
        String[] enemy_moves = {"Simp Horse", "Low Profile Rook", "Cheeky Queen", "Magic"};
        
        // looping until someone wins
        while(player_health > 0 && enemy_health > 0)
        {
            // if user's turn
            if(turn == 1)
            {
                // displaying attack and asking for user choice
                attackDisplay("Player");
                choice = sc.nextInt();
                
                // checking if the choice is valid
                if(choice > 4 || choice < 0){
                    slowPrint("Invalid attack provided. Try again.\n", dialogueSpeed);
                    continue;
                
                }
                
                // picking a random damage value from the array
                System.out.println("");
                dmg = damage[rn.nextInt(15)];
                
                // damaging the enemy or healing the player based on input
                damageEntity(dmg, true, (choice == 3));
                if(choice != 3)
                slowPrint("Your move dealt " + dmg + " damage.\nFriend\'s health is at " + enemy_health + " hp", dialogueSpeed);
                else
                slowPrint("Your move healed " + dmg + " damage.\nYour health is at " + player_health + " hp", dialogueSpeed);
                turn++;
                
            }
            // friend's choice
            else{
              // picking random damage from dmg array
              dmg = damage[rn.nextInt(11)];
              // generating friend choice with random numbers
              choice = rn.nextInt(4);           
              // choosing the friend move
              String move = enemy_moves[choice];
              // damaging player or healing friend based on input
              damageEntity(dmg, false, (choice == 3));
              if(choice != 3)
              slowPrint("\n\nFriend used " + move + " which dealt " + dmg + " damage.\nYour health is at " + player_health + " hp.\n", dialogueSpeed);
              else
              slowPrint("\n\nFriend used " + move + " which healed " + dmg + " damage.\nFriend\'s health is at " + enemy_health + " hp.\n", dialogueSpeed);            
              turn--;
            }
            
            // checking if the player health or friend health exceed 100
            if(player_health > 100) player_health = 100;
            if(enemy_health > 100) enemy_health = 100;
        }
        
        // checking if player health is more than enemy
        if(player_health > enemy_health){
          slowPrint("[Player] Better luck next time man.", dialogueSpeed);
        Thread.sleep(sleepTime); // player wins
        }
        else if(enemy_health > player_health){
          slowPrint("[Friend] This chess variant is fun, isnt it?", dialogueSpeed);
        Thread.sleep(sleepTime); // enemy wins
        }
    }
}
