import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { HttpClientModule} from '@angular/common/http';
import { PatientListComponent } from './patient-list/patient-list.component';
import { PatientService } from './patient.service';
import { PatientInsertComponent } from './patient-insert/patient-insert.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { HomeComponent } from './home/home.component';
import { ReactiveFormsModule } from '@angular/forms';
import { LoginComponent } from './login/login.component';

@NgModule({
  declarations: [
    AppComponent,
    PatientListComponent,
    PatientInsertComponent,
    PageNotFoundComponent,
    HomeComponent,
    LoginComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NgbModule,
    HttpClientModule,
    ReactiveFormsModule
  ],
  providers: [PatientService],
  bootstrap: [AppComponent]
})
export class AppModule { }
