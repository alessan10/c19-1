#!/usr/bin/env python
# -*- coding: utf-8 -*-
# pylint: disable=W0613, C0116
# type: ignore[union-attr]
# This program is dedicated to the public domain under the CC0 license.

# COSE DA FARE:
# 1) ELIMINARE IL BOTTONE CONFERMA riga 68
# 2) impostare il msg di conferma a riga 129
# 3) aggiungere l'inserimento dello stato positivo/negativo?
# 4) varie ed eventuali in base al buonsenso


"""
First, a few callback functions are defined. Then, those functions are passed to
the Dispatcher and registered at their respective places.
Then, the bot is started and runs until we press Ctrl-C on the command line.

Usage:
Example of a bot-user conversation using ConversationHandler.
Send /start to initiate the conversation.
Press Ctrl-C on the command line or send a signal to the process to stop the
bot.
"""

import logging
import requests

# RITORNARE DA 22 A 26 DOPO CHE HAI SISTEMATO IL SERVER.GO
#import requests
# data = {'chat_id': '72600457', 'voice': 'AwADBAADPAYAAvFWCVFZFfPyZdGLfhYE'}
#url = f'https://api.telegram.org/bot{token}/sendVoice'
#response = requests.post(url, data=data)
#response = requests.get(url, params=data)
#print(response.json())

from typing import Dict
from data import token

from telegram import ReplyKeyboardMarkup, Update, InlineKeyboardMarkup, InlineKeyboardButton
from telegram.ext import (
    Updater,
    CommandHandler,
    MessageHandler,
    Filters,
    ConversationHandler,
    CallbackContext,
    CallbackQueryHandler,
)


# Enable logging
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO
)

logger = logging.getLogger(__name__)

ASK_FOR_INPUT, SAVE_INPUT, FINE, NAME, END, POST  = range(6)

def start(update: Update, context: CallbackContext) -> int:
    print("[ START ]")
    user_data = context.user_data
    text = (
        'Utilizzeremo i tuoi dati per informarti qualora qualcuno dei soggetti '
        'con cui sei venuto a contatto, risultasse positivo al test per il covid-19\n\n'
        'Inserisci i tui dati:'
    )
    buttons = [
        [
            InlineKeyboardButton(text='Nome e Cognome', callback_data=str(NAME)),
            InlineKeyboardButton(text='Conferma', callback_data=str(END)),
        ]
    ]
    keyboard = InlineKeyboardMarkup(buttons)
    update.message.reply_text(text=text, reply_markup=keyboard)

    
    return ASK_FOR_INPUT

def ask_for_input(update: Update, context: CallbackContext) -> None:
    """Prompt user to input data for selected feature."""
    context.user_data[NAME] = update.callback_query.data
    text = 'Inserisci Nome e Cognome.'

    update.callback_query.answer()
  
    update.callback_query.edit_message_text(text=text)

    return SAVE_INPUT


def save_input(update: Update, context: CallbackContext) -> None:
    """Save input for feature and return to feature selection."""
    print("[ SAVE_INPUT ]")
    user_data = context.user_data
    user_data[NAME] = update.message.text
    print("Nome Completo: ", user_data[NAME])
    text = 'Registrazione in corso...'
    update.message.reply_text(text=text)

    return post(update, context)

def post(update: Update, context: CallbackContext) -> None:
  print("[ POST ]")
  user_data = context.user_data
  user = update.message.from_user
  # payload = {
  #   'username': user['username'],
  #   'chatid': user['id'],
  #   'name' : user_data[NAME]
  # }
  print("name",user_data[NAME])
  print("chatid", user['id'])
  
  # b'{"Machine Name":"'+hostname+'"}', None, True)
  payload = {"name":""+user_data[NAME]+"","chatid": ""+str(user['id'])+"","covid": "negativo"}

  #print("Payload[username]: ", payload["username"] )
  print("Payload[chatid]: ", payload["chatid"] )
  print("Payload[name]: ", payload["name"] )
  print("Payload[covid]: ", payload["covid"] )

  print("ConversationHandler.END: ", ConversationHandler.END )
  # la SEARCH FUNZIONA
  #response = requests.post(url='http://localhost:8081/search',data=payload)
  # la ADD funziona!
  response = requests.post(url='http://localhost:8081/add',json=payload)
  print("response: ", response.status_code)

  #AGGIUNGERE LA CONFERMA CHE L'INSERIMENTO è ANDATO A BUON FINE (se status_code = 200)
  return ConversationHandler.END


  

def stop_nested(update: Update, context: CallbackContext) -> None:
    """Completely end conversation from within nested conversation."""
    update.message.reply_text('Okay, bye.')

    return ConversationHandler.END



def main() -> None:
    # Create the Updater and pass it your bot's token.
    # Make sure to set use_context=True to use the new context based callbacks
    # Post version 12 this will no longer be necessary
    updater = Updater(token, use_context=True)

    # Get the dispatcher to register handlers
    dispatcher = updater.dispatcher

    # Add conversation handler with the states CHOOSING, TYPING_CHOICE and TYPING_REPLY
    conv_handler = ConversationHandler(
        entry_points=[CommandHandler('start', start)],
        states={
            ASK_FOR_INPUT: [
                CallbackQueryHandler(ask_for_input, pattern='^(?!' + str(END) + ').*$') #il bot ignora tutto ciò che non sia testo
            ],
            SAVE_INPUT:[
                MessageHandler(Filters.text , save_input)
            ]
        },
        fallbacks=[
            CommandHandler('stop', stop_nested),
        ]
        # fallbacks ci serve se lo stato dell'utente non è nessuno dei precedenti definiti      
    )

    dispatcher.add_handler(conv_handler)

    # Start the Bot
    updater.start_polling()

    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()


if __name__ == '__main__':
    main()
