#!/usr/bin/env python
# -*- coding: utf-8 -*-
# pylint: disable=W0613, C0116
# type: ignore[union-attr]
# This program is dedicated to the public domain under the CC0 license.

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
from typing import Dict
from data import token

from telegram import ReplyKeyboardMarkup, Update
from telegram.ext import (
    Updater,
    CommandHandler,
    MessageHandler,
    Filters,
    ConversationHandler,
    CallbackContext,
)

# Enable logging
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO
)

logger = logging.getLogger(__name__)

TYPING_SURNAME, DONE  = range(2)

# reply_keyboard = [
#     ['Age', 'Favourite colour'],
#     ['Number of siblings', 'Something else...'],
#     ['Done'],
# ]
# markup = ReplyKeyboardMarkup(reply_keyboard, one_time_keyboard=True)


# def facts_to_str(user_data: Dict[str, str]) -> str:
#     facts = list()

#     for key, value in user_data.items():
#         facts.append('{} - {}'.format(key, value))

#     return "\n".join(facts).join(['\n', '\n'])


def start(update: Update, context: CallbackContext) -> int:
    user = update.message.from_user
    first_name = str(user['first_name'])
    last_name = str(user['last_name'])
    if(str(user['last_name']) == 'None'):
      last_name = ''

    update.message.reply_text("Utilizzeremo i tuoi dati per informarti qualora qualcuno dei soggetti con cui sei venuto a contatto, risultasse positivo al test per il covid-19 \n"
    "I tuoi dati di cui siamo a disposizione sono: \n\n Nome: " "{}" "\nCognome: " "{}"
    .format(first_name, last_name)
    )
    
    print('You talk with user {}, his user ID: {}, name: {}, surname:  {} '
    .format(user['username'], user['id'], user['first_name'], user['last_name'] )  )
    

    if(str(user['last_name']) == 'None'):
      update.message.reply_text('Cognome mancante, inserisci il cognome: ')
      last_name = ''
      return TYPING_SURNAME

    #Continua solo se nome e cognome sono già presenti
    full_name = first_name + ' ' + last_name
    payload = {
      "username": user['username'],
      "chatid": user['id'],
      "name" : full_name
    }
    
    print(payload["name"] )
    return DONE
    
def typing_surname(update: Update, context: CallbackContext) -> int:
    user = update.message.from_user
    first_name = str(user['first_name'])
    last_name = update.message.text
        
    print(last_name)
    full_name = first_name + ' ' + last_name
    payload = {
      "username": user['username'],
      "chatid": user['id'],
      "name" : full_name
    }
    print(payload["name"])
    return DONE


def fine(update: Update, context: CallbackContext) -> int:
    # user_data = context.user_data
    user = update.message.from_user
    first_name = str(user['first_name'])
    last_name = str(user['last_name'])

    update.message.reply_text(
        "Nome: " "{}" "\nCognome: " "{}".format(first_name, last_name)
    )

    user_data.clear()
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
            TYPING_SURNAME: [
                MessageHandler(
                    Filters.text & ~(Filters.command | Filters.regex('^Done$')), typing_surname
                )
            ],
            DONE: [
                MessageHandler(
                    Filters.text & ~(Filters.command | Filters.regex('^Done$')), fine
                )
            ]
        },
        fallbacks=[MessageHandler(Filters.regex('^Done$'), fine)],
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
