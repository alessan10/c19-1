import { Component, OnInit } from '@angular/core';
import { pipe } from 'rxjs';
import { map } from 'rxjs/operators';
import { IPatient, Patient } from '../IPatient';
import { PatientService } from '../patient.service';

@Component({
  selector: 'app-patient-list',
  template: `
  <button (click)="getGraph()" class="btn btn-primary"> Get graph</button>
  <h2> Patients list: </h2>
  <h3> {{ errorMsg }} </h3>
  <ul *ngFor="let patient of patients ">
    <li> {{ patient.patient.name }}</li>
  </ul>

  `,
  styles: []
})
export class PatientListComponent implements OnInit {

  // public patients: any[] = [];
  public patients: Patient[] = [];
  public errorMsg: any;


  constructor(private _patientService: PatientService) { }

  ngOnInit(): void {

  }

  getGraph(){
    this._patientService.getPatients()
    .subscribe( data => this.patients = data );

    ;



  }

}


